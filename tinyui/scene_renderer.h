#ifndef SCENE_RENDERER_H
#define SCENE_RENDERER_H

#include "drawable.h"
#include "scene.h"

class SceneRenderer {
public:
    SceneRenderer(Display &display, int frame_ms=20)
    : _display(display), _frame_ms(frame_ms),
      _debug(false), _blink(false)
    {}

    void renderScene(Scene *scene, bool show_controls);

    void setDebug(bool on) {
        _debug = on;
    }

    void setBlink(bool on) {
        _blink = on;
    }

private:
    Display &_display;
    int _frame_ms;
    bool _debug;
    bool _blink;

    // state
    unsigned long _last_frame_ms;
    unsigned long _last_delta_ms;
    unsigned long _last_end;
    unsigned long _last_start;
    unsigned long _last_blink;
    bool _blink_state;

    void drawDebugStatus();
};

#endif
