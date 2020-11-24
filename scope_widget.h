#ifndef SCOPE_WIDGET_H
#define SCOPE_WIDGET_H

#include "widget.h"
#include "analyze_avgarray.h"

class ScopeWidget : public Widget
{
public:
    ScopeWidget(int x, int y, int w, int h, int window_size=1)
        : Widget(x, y, w, h)
    {
        setWindowSize(window_size);
    }

    void setWindowSize(int window_size) {
        _window_size = window_size;
        // how many ms are displayed in widget?
        int total_ms = window_size * _w * 1000 / 44100;
        if(total_ms > 100) {
            _grid_unit_ms = 100; // 100 ms grid
        }
        else if(total_ms > 10) {
            _grid_unit_ms = 10; // 10 ms grid
        }
        else {
            _grid_unit_ms = 1;
        }

        // how many pixels are n ms in scope display?
        _grid_w = _grid_unit_ms * 44100 / (window_size * 1000); 
    }

    int getGridUnitMs() {
        return _grid_unit_ms;
    }

    void drawSamples(Drawable &d, int num_samples, int16_t *samples, int16_t color);
    void drawGrid(Drawable &d);

private:
    int _num_samples;
    int16_t *_samples;

    int _window_size;
    int _grid_w;
    int _grid_unit_ms;
 
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
