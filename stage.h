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

    void setActiveScene(int num)
    {
        _selectedSceneParam.setValue(num);
    }

    void handle();

    Scene *getActiveScene();

private:
    enum InputState {
        WIDGET_NORMAL,
        WIDGET_SELECT,
        SCENE_SELECT
    };

    SceneRenderer _renderer;
    EventSource &_eventSource;
    const std::vector<Scene *> _scenes;
    InputState _inputState;
    IntRangeParam _selectedSceneParam;
    IntTextParamControl _selectedSceneControl;

    void handleWidgetNormalEvent(Scene *scene, const Event &e);
    void handleWidgetSelectEvent(const Event &e);
    void handleSceneSelectEvent(const Event &e);

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
