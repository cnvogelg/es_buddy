#ifndef SCENE_RENDERER_H
#define SCENE_RENDERER_H

#include "drawable.h"
#include "scene.h"

class SceneRenderer {
public:
    SceneRenderer(Display &display, int frame_ms=20, bool debug=false)
    : _display(display), _frame_ms(frame_ms), _debug(debug)
    {}

    void renderScene(Scene *scene);

private:
    Display &_display;
    int _frame_ms;
    bool _debug;

    // state
    unsigned long _last_frame_ms;
    unsigned long _last_delta_ms;
    unsigned long _last_end;
    unsigned long _last_start;

    void drawDebugStatus();
};

#endif
