#include <Arduino.h>
#include "stage.h"

void Stage::render()
{
    Scene *s = _active_scene;

    // check if we have to wait for this frame
    // since the last one was to short
    if(_last_start > 0) {
        unsigned long now = millis();
        long delta = now - _last_start;
        if(delta < _frame_ms) {
            delay(_frame_ms - delta);
        }
    }

    bool do_draw = true;
    if(s != nullptr) {
        do_draw = s->preDraw();
    }

    // render current scene
    if(do_draw) {
        unsigned long start = millis();
        _display.displayClear();
        if(s != nullptr) {
            s->draw(_display);
        }
        if(_debug) {
            drawDebugStatus();
        }
        _display.displayUpdate();
        unsigned long end = millis();

        // update state
        _last_frame_ms = end - start;
        _last_delta_ms = start - _last_start;
        _last_end = end;
        _last_start = start;
    }

    if(s != nullptr) {
        s->postDraw(do_draw);
    }
}

void Stage::drawDebugStatus()
{
    int _mx = _display.getMaxCursorX() - 6;
    int _my = _display.getMaxCursorY();
    Print &p = _display.getPrint();
    _display.setCursor(_mx, _my);
    p.print("fms=");
    p.print(_last_frame_ms);
    
    _display.setCursor(_mx, _my - 1);
    p.print("dlt=");
    p.print(_last_delta_ms);

    _display.setCursor(_mx, _my - 2);
    p.print("mem=");
    p.print(AudioMemoryUsage());

    _display.setCursor(_mx, _my - 3);
    p.print("cpu=");
    p.print(AudioProcessorUsage());
}