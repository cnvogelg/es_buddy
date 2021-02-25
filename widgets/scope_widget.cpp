#include <Arduino.h>
#include "scope_widget.h"

void ScopeWidget::init()
{
    _channelX.begin();
    _channelY.begin();
}

void ScopeWidget::exit()
{
    _channelX.stop();
    _channelY.stop();
}

void ScopeWidget::setWindowSize(int windowSize) {
    _window_size = windowSize;
    // how many ms are displayed in widget?
    int total_ms = windowSize * _geo.w() * 1000 / 44100;
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
    _grid_w = _grid_unit_ms * 44100 / (windowSize * 1000); 

    _channelX.setWindowSize(windowSize);
    _channelY.setWindowSize(windowSize);
}

void ScopeWidget::draw(Drawable &d, bool hilite)
{
    drawGrid(d);
    drawSamples(d, _channelX.getArray(), COLOR_GREEN);
    drawSamples(d, _channelY.getArray(), COLOR_YELLOW);
    if(hilite) {
        setHiliteColor(d);
        drawBorder(d);
    }
}

void ScopeWidget::drawGrid(Drawable &d)
{
    // draw grid
    d.setColor(COLOR_GRAY);
    drawBorder(d);
    int y_mid = _geo.y() + _geo.h() / 2;
    d.hline(_geo.x(), y_mid, _geo.w());
    int y_quart = _geo.h() / 4;
    d.hline(_geo.x(), y_mid - y_quart, _geo.w());
    d.hline(_geo.x(), y_mid + y_quart, _geo.w());

    // draw ms grid
    if(_grid_w > 2) {
        int x = _grid_w;
        while(x < _geo.w()) {
            d.vline(_geo.x() + x, _geo.y(), _geo.h());
            x += _grid_w;
        }
    }
}

void ScopeWidget::drawSamples(Drawable &d, SampleArray &array, int16_t color)
{
    int x = _geo.x();
    int old_y_avg;
    int num_samples = array.size();
    int16_t *samples = array.buffer();

    // draw wave form
    d.setColor(color);
    for(int i=0;i<num_samples;i++) {
        if(i == _geo.w()) {
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
