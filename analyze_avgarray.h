#ifndef analyze_avgarray_h_
#define analyze_avgarray_h_

#include "Arduino.h"
#include "AudioStream.h"

#include "sample_array.h"

class AudioAnalyzeAvgArray : public AudioStream
{
public:
	enum TriggerMode { RISE, FALL };

	AudioAnalyzeAvgArray(int size) 
		: AudioStream(1, _inputQueueArray),
		  _sample_buffers{size,size}
	{
		_window_size = 1;
		_state = State::DONE;
		_trigger_value = 0;
		_trigger_mode = TriggerMode::RISE;
		_trigger_timeout = 44100 * 20 / 1000; // samples for 20ms
		_active_buffer = 0;
		_num_samples = size;
		_active_samples = _sample_buffers[0].buffer();
	}

	int getWindowSize() { return _window_size; }
	int getTriggerValue() { return _trigger_value; }
	TriggerMode getTriggerMode() { return _trigger_mode; }

	void begin() {
		__disable_irq();
		reset();
		__enable_irq();
	}

	SampleArray &getArray(void) {
		__disable_irq();
		int buffer_idx = _active_buffer;
		// active buffer is filled?
		if(_state == State::DONE) {
			// return currently filled buffer and restart with other buffer
			_active_buffer = 1 - _active_buffer;
			_active_samples = _sample_buffers[_active_buffer].buffer();
			// retrigger
			reset();
		} else {
			// return inactive buffer for now
			buffer_idx = 1 - buffer_idx;
		}
		__enable_irq();
		// always return the inactive buffe
		return _sample_buffers[buffer_idx];
	}

	void stop(void) {
		__disable_irq();
		_state = State::DONE;
		__enable_irq();
	}

	int setWindowSize(int window_size)
	{
		if(window_size < 1) {
			window_size = 1;
		}
        if(window_size > 64) {
            window_size = 64;
        }
		__disable_irq();
		_window_size = window_size;
		reset();
		__enable_irq();
        return window_size;
	}

	void setTrigger(int value, TriggerMode mode, int timeout_ms)
	{
		__disable_irq();
		_trigger_value = value;
		_trigger_mode = mode;
		_trigger_timeout = 44100 * timeout_ms / 1000;
		reset();
		__enable_irq();
	}

	virtual void update(void);

private:

	void reset(void) {
		_sample_idx = 0;
		_window_pos = 0;
		_state = State::FIRST_SAMPLE;
	}

	audio_block_t *_inputQueueArray[1];
	int _window_size;
	int _num_samples;
	SampleArray _sample_buffers[2];
	int _trigger_value;
	TriggerMode _trigger_mode;
	int _trigger_timeout;
	enum State { FIRST_SAMPLE, CHECK_TRIGGER, RECORD, DONE };

	// state
	int16_t *_active_samples;
	int _active_buffer;
	int _sample_idx;
	int _window_pos;
	State _state; 
	int16_t _last_sample;
    int _checked_samples;
	int32_t _cur_sum;
};

#endif