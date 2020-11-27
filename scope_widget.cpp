#include <Arduino.h>
#include "scope_widget.h"

AudioStream *ScopeWidget::addAudioStream(int16_t color)
{
    if(_numChannels == MAX_CHANNELS) {
        return nullptr;
    }

    AudioAnalyzeAvgArray *result = new AudioAnalyzeAvgArray(_w);
    if(result == nullptr) {
        return nullptr;
    }

    _channels[_numChannels] = result;
    _colors[_numChannels] = color;
    _numChannels++;

    return result;
}

void ScopeWidget::init()
{
    for(int i=0;i<_numChannels;i++) {
        _channels[i]->begin();
    }    
}

void ScopeWidget::exit()
{
    for(int i=0;i<_numChannels;i++) {
        _channels[i]->stop();
    }    
}

void ScopeWidget::setWindowSize(int windowSize) {
    _window_size = windowSize;
    // how many ms are displayed in widget?
    int total_ms = windowSize * _w * 1000 / 44100;
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

    for(int i=0;i<_numChannels;i++) {
        _channels[i]->setWindowSize(windowSize);
    }
}

void ScopeWidget::draw(Drawable &d)
{
    drawGrid(d);
    for(int i=0;i<_numChannels;i++) {
        drawSamples(d, _channels[i]->getArray(), _colors[i]);
    }
}

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
