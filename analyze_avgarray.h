#ifndef analyze_avgarray_h_
#define analyze_avgarray_h_

#include "Arduino.h"
#include "AudioStream.h"

class AudioAnalyzeAvgArray : public AudioStream
{
public:
	enum TriggerMode { RISE, FALL };

	AudioAnalyzeAvgArray(int num_samples, int16_t *samples) 
		: AudioStream(1, _inputQueueArray) 
	{
		_num_samples = num_samples;
		_samples = samples;
		_window_size = 1;
		_state = State::DONE;
		_trigger_value = 0;
		_trigger_mode = TriggerMode::RISE;
		_trigger_timeout = 44100 * 20 / 1000; // samples for 20ms
	}

	int numSamples() { return _num_samples; }
	int16_t *samples() { return _samples; }
	int getWindowSize() { return _window_size; }
	int getTriggerValue() { return _trigger_value; }
	TriggerMode getTriggerMode() { return _trigger_mode; }

	void begin(void) {
		__disable_irq();
		reset();
		__enable_irq();
	}

	bool available(void) {
		__disable_irq();
		bool flag = (_state == State::DONE);
		__enable_irq();
		return flag;
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
	int _num_samples;
	int _window_size;
	int16_t *_samples;
	int _trigger_value;
	TriggerMode _trigger_mode;
	int _trigger_timeout;
	enum State { FIRST_SAMPLE, CHECK_TRIGGER, RECORD, DONE };

	// state
	int _sample_idx;
	int _window_pos;
	State _state; 
	int16_t _last_sample;
    int _checked_samples;
	int32_t _cur_sum;
};

#endif