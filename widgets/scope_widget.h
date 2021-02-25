#ifndef SCOPE_WIDGET_H
#define SCOPE_WIDGET_H

#include "esb_tinyui.h"
#include "esb_audio.h"

class ScopeWidget : public Widget
{
public:
    ScopeWidget(const Geo &geo, int windowSize=1)
        : Widget(geo),
          _channelX(geo.w()),
          _channelY(geo.w())
    {
        setWindowSize(windowSize);
    }

    AudioStream &getAudioInputX() {
        return _channelX;
    }

    AudioStream &getAudioInputY() {
        return _channelY;
    }

    void setWindowSize(int windowSize);
    int getWindowSize() {
        return _window_size;
    }

    int getGridUnitMs() {
        return _grid_unit_ms;
    }

    virtual void init();
    virtual void draw(Drawable &d, bool hilite);
    virtual void exit();

private:
    int _window_size;
    int _grid_w;
    int _grid_unit_ms;

    AudioAnalyzeAvgArray _channelX;
    AudioAnalyzeAvgArray _channelY;

    void drawSamples(Drawable &d, SampleArray &array, int16_t color);
    void drawGrid(Drawable &d);

    int map_sample_value(int16_t val)
    {
        int out = _geo.y2() - (val + 32768) * _geo.h() / 65536;
        if(out < _geo.y()) {
            return _geo.y();
        }
        else if(out >= _geo.y2()) {
            return _geo.y2();
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
