#ifndef STAGE_H
#define STAGE_H

#include <vector>

#include "drawable.h"
#include "param.h"
#include "param_widget.h"
#include "event.h"
#include "scene.h"
#include "scene_renderer.h"

class Stage {
public:
    Stage(Display &display, EventSource &eventSource,
        const std::vector<Scene *> &scenes, 
        int frame_ms=20);

    Scene *getActiveScene();
    void setActiveScene(int num);

    void handle();

private:
    enum InputState {
        WIDGET_NORMAL,
        WIDGET_SELECT
    };

    SceneRenderer _renderer;
    EventSource &_eventSource;
    const std::vector<Scene *> _scenes;
    InputState _inputState;
    IntRangeParam _selectedSceneParam;
    IntTextParamControl _selectedSceneControl;
    Scene *_activeScene;

    void handleWidgetNormalEvent(Scene *scene, const Event &e);
    void handleWidgetSelectEvent(Scene *scene, const Event &e);
    void changeActiveScene(int idx);

    Geo getSceneSelectGeo(Display &display) {
        return Geo(0,
            display.getDisplayHeight() - display.getFontHeight() - 2,
            display.getDisplayWidth() / 2,
            display.getFontHeight() + 2);
    }

    const char *getSceneName(int idx) {
        return _scenes[idx]->getName();
    }
};

#endif
