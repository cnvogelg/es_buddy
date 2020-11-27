#ifndef SCOPE_WIDGET_H
#define SCOPE_WIDGET_H

#include "widget.h"
#include "sample_array.h"
#include "analyze_avgarray.h"

class ScopeWidget : public Widget
{
public:
    ScopeWidget(int x, int y, int w, int h, int windowSize=1)
        : Widget(x, y, w, h)
    {
        setWindowSize(windowSize);
    }

    AudioStream *addAudioStream(int16_t color);

    void setWindowSize(int windowSize);
    int getWindowSize() {
        return _window_size;
    }

    int getGridUnitMs() {
        return _grid_unit_ms;
    }

    virtual void init();
    virtual void draw(Drawable &d);
    virtual void exit();

private:
    int _window_size;
    int _grid_w;
    int _grid_unit_ms;

    static const int MAX_CHANNELS = 4;
    int _numChannels = 0;

    AudioAnalyzeAvgArray *_channels[MAX_CHANNELS];
    int16_t _colors[MAX_CHANNELS];

    void drawSamples(Drawable &d, SampleArray &array, int16_t color);
    void drawGrid(Drawable &d);

    int map_sample_value(int16_t val)
    {
        int out = _y + _h - 1 - (val + 32768) * _h / 65536;
        if(out < _y) {
            return _y;
        }
        else if(out >= (_y + _h)) {
            return _y + _h - 1;
        }
        else {
            return out;
        }
    }

    void draw_skip_line(Drawable &d, int16_t x, int16_t y1, int y2)
    {
        if(y1 == y2) {
            d.pixel(x, y1);
        } else if(y1 < y2) {
            int h = y2 - y1;
            d.vline(x, y1, h);
        } else {
            int h = y1 - y2;
            d.vline(x, y2, h);
        }
    }
};

#endif // SCOPE_WIDGET
