#include <Arduino.h>
#include "analyze_avgarray.h"

void AudioAnalyzeAvgArray::update(void)
{
	audio_block_t *block;
	const int16_t *p, *end;

	block = receiveReadOnly();
	if (!block) {
		return;
	}
	p = block->data;
	end = p + AUDIO_BLOCK_SAMPLES;
	do {
		int16_t d=*p++;
        switch(_state) {
            case State::FIRST_SAMPLE:
                _last_sample = d;
                _state = State::CHECK_TRIGGER;
                _checked_samples = 0;
                break;
            case State::CHECK_TRIGGER:
                if(_trigger_mode == TriggerMode::RISE) {
                    if((_last_sample <= _trigger_value) && (d >= _trigger_value)) {
                        _state = State::RECORD;
                    }
                }
                else {
                    if((_last_sample >= _trigger_value) && (d <= _trigger_value)) {
                        _state = State::RECORD;
                    }
                }
                _last_sample = d;
                _checked_samples++;
                // if no trigger found abort (0.1s)
                if(_checked_samples == _trigger_timeout) {
                    _state = State::RECORD;
                }
                if(_state == State::CHECK_TRIGGER) {
                    break;
                }
                // otherwise fall through
            case State::RECORD:
            {
                // update window min/max
                if(_window_pos == 0) {
                    // reset sum
                    _cur_sum = 0;
                }
                // accumulate sum
                _cur_sum += d;
                // window complete?
                _window_pos ++;
                if(_window_pos == _window_size) {
                    // calc and store avg
                    _samples[_sample_idx] = _cur_sum / _window_size;
                    // prepare next sample
                    _sample_idx++;
                    // sample buffer filled completely
                    if(_sample_idx == _num_samples) {
                        _state = State::DONE;
                    }
                    else {
                        // reset window
                        _window_pos = 0;
                    }
                }
                break;
            }
            case State::DONE:
                break;
        }
	} while (p < end);
	release(block);
}
