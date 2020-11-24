#ifndef STAGE_H
#define STAGE_H

#include "drawable.h"
#include "scene.h"

class Stage {
public:
    Stage(Display &display, int frame_ms=20, bool debug=false)
        : _display(display),
          _frame_ms(frame_ms),
          _debug(debug),
          _active_scene(nullptr)
    {}

    void setDebug(bool debug)
    {
        _debug = debug;
    }

    void setActiveScene(Scene *scene)
    {
        if(_active_scene != nullptr) {
            _active_scene->leaveScene();
        }

        _active_scene = scene;

        if(_active_scene != nullptr) {
            _active_scene->enterScene();
        }
    }

    void render();

private:
    Display &_display;
    int _frame_ms;
    bool _debug;
    Scene *_active_scene;

    // state
    unsigned long _last_frame_ms;
    unsigned long _last_delta_ms;
    unsigned long _last_end;
    unsigned long _last_start;

    void drawDebugStatus();
};

#endif
