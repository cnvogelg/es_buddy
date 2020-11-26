#include <Arduino.h>
#include "scope_widget.h"

void ScopeWidget::drawGrid(Drawable &d)
{
    // draw grid
    d.setColor(COLOR_GRAY);
    drawBorder(d);
    int y_mid = _y + _h / 2;
    d.hline(_x, y_mid, _w);
    int y_quart = _h / 4;
    d.hline(_x, y_mid - y_quart, _w);
    d.hline(_x, y_mid + y_quart, _w);

    // draw ms grid
    if(_grid_w > 2) {
        int x = _grid_w;
        while(x < _w) {
            d.vline(_x + x, _y, _h);
            x += _grid_w;
        }
    }
}

void ScopeWidget::drawSamples(Drawable &d, SampleArray &array, int16_t color)
{
    int x = _x;
    int old_y_avg;
    int num_samples = array.size();
    int16_t *samples = array.buffer();

    // draw wave form
    d.setColor(color);
    for(int i=0;i<num_samples;i++) {
        if(i == _w) {
            break;
        }

        int16_t avg = samples[i];
        int y_avg = map_sample_value(avg);

        if(i>0) {
            draw_skip_line(d, x, old_y_avg, y_avg);
        } 

        old_y_avg = y_avg;
        x++;
    }
}
