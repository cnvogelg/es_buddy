#ifndef SPECTRUM_WIDGET_H
#define SPECTRUM_WIDGET_H

#include <Audio.h>

#include "esb_tinyui.h"
#include "esb_audio.h"

class SpectrumWidget : public Widget
{
public:
    SpectrumWidget(const Geo &geo)
        : Widget(geo)
    {
    }

    AudioStream &getAudioInput() {
        return _fft;
    }

    virtual void init() override;
    virtual void draw(Drawable &d, bool hilite) override;
    virtual void exit() override;

private:
    float _minHz = 0.0;
    float _maxHz = 22050.0f;
    float _posDb = 20.0;
    float _rangeDb = 80.0;
    const float _numBins = 512;
    const float _hzPerBin = 22050.0f / _numBins;

    float _xLogFactor;
    AudioAnalyzeFFT1024   _fft;

    void drawBins(Drawable &d);
    void drawGrid(Drawable &d);
    void drawGridX(Drawable &d);
    void drawGridY(Drawable &d);

    int mapX(float hz) {
        float r = (hz - _minHz) / _maxHz;
        float x = powf(r, _xLogFactor);
        if(x < 1.0f) {
            return _geo.x() + (int)(x * _geo.w());
        } else {
            return -1;
        }
    }

    int mapYDb(float db) {
        if(db > _posDb) {
            return -1;
        }
        if(db < (_posDb - _rangeDb)) {
            return -1;
        }        
        float r = (_posDb - db) / _rangeDb;
        return _geo.y() + (int)(r * _geo.h());
    }

    void drawGridXLine(Drawable &d, float hz) {
        int x = mapX(hz);
        if(x != -1) {
            d.vline(x, _geo.y(), _geo.h());
        }
    }
};

#endif // SCOPE_WIDGET
