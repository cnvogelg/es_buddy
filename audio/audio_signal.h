#ifndef audio_signal_h
#define audio_signal_h

inline float decibelsToAmplitude(float db) {
	return powf(10.0f, db * 0.05f);
}

inline float amplitudeToDecibels(float amplitude) {
	if (amplitude < 0.000001f) {
		return -120.0f;
	}
	return 20.0f * log10f(amplitude);
}

inline float signal_clamp(float v, float min, float max) {
    if(v < min) {
        return min;
    }
    else if(v > max) {
        return max;
    }
    else {
        return v;
    }
}

#endif
