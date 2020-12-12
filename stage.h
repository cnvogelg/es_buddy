#ifndef STAGE_H
#define STAGE_H

#include <vector>

#include "drawable.h"
#include "event.h"
#include "scene.h"
#include "scene_renderer.h"

class Stage {
public:
    Stage(Display &display, EventSource &eventSource, 
        const std::vector<Scene *> &scenes, 
        int frame_ms=20, bool debug=false)
        : _renderer(display, frame_ms, debug),
          _eventSource(eventSource),
          _scenes(scenes),
          _active_scene(nullptr)
    {
        setActiveScene(scenes[0]);
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

    void handle();

private:
    SceneRenderer _renderer;
    EventSource &_eventSource;
    const std::vector<Scene *> _scenes;
    Scene *_active_scene;
};

#endif
