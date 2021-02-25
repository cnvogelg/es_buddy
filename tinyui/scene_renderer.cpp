#include <Arduino.h>
#include "scene_renderer.h"

void SceneRenderer::renderScene(Scene *s, bool show_controls)
{
    // check if we have to wait for this frame
    // since the last one was to short
    if(_last_start > 0) {
        unsigned long now = millis();
        long delta = now - _last_start;
        if(delta < _frame_ms) {
            delay(_frame_ms - delta);
        }
    }

    // render current scene
    unsigned long start = millis();
    _display.displayClear();
    if(s != nullptr) {
        bool allowHilite = !_blink || _blink_state;
        s->draw(_display, allowHilite, show_controls);
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

    // update blink: 500ms
    long delta = start - _last_blink;
    if(delta > 500) {
        _blink_state = !_blink_state;
        _last_blink = start;
    }
}

void SceneRenderer::drawDebugStatus()
{
    _display.setTextColor(COLOR_WHITE);
    _display.setTextScale(1,1);

    int _mx = _display.getMaxCursorCol() - 7;
    int _my = _display.getMaxCursorRow();
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
