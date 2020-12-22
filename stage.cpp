#include <Arduino.h>
#include "stage.h"

Stage::Stage(Display &display, EventSource &eventSource, 
    const std::vector<Scene *> &scenes, 
    int frame_ms)
    : _renderer(display, frame_ms),
        _eventSource(eventSource),
        _scenes(scenes),
        _inputState(WIDGET_NORMAL),
        _selectedSceneParam(0, 0, scenes.size(), 1),
        _selectedSceneControl(getSceneSelectGeo(display), "sc:", &_selectedSceneParam)
{
    for(Scene *s : scenes) {
        s->setExtraWidget(&_selectedSceneControl);
    }
    _selectedSceneParam.setMapper([=](int idx)->const char * { return this->getSceneName(idx); });

    _renderer.setBlink(true);
    _renderer.setDebug(true);
}

Scene *Stage::getActiveScene()
{
    int activeIndex = _selectedSceneParam.getValue();
    if(activeIndex < (int)_scenes.size()) {
        return _scenes[activeIndex];
    } else {
        return nullptr;
    }
}

void Stage::handle() 
{
    Scene *activeScene = getActiveScene();

    Event e;
    if(_eventSource.pollEvent(e)) {
        switch(_inputState) {
            case WIDGET_NORMAL:
                handleWidgetNormalEvent(activeScene, e);
                break;
            case WIDGET_SELECT:
                handleWidgetSelectEvent(e);
                break;
            case SCENE_SELECT:
                handleSceneSelectEvent(e);
                break;
        }
    }

    _renderer.renderScene(activeScene);
}

void Stage::handleWidgetNormalEvent(Scene *scene, const Event &e)
{
    if(scene == nullptr) {
        return;
    }

    switch(e.type) {
        case EventType::INC_VALUE:
            scene->handleEvent(ControlEvent::INC_VALUE);
            break;
        case EventType::DEC_VALUE:
            scene->handleEvent(ControlEvent::DEC_VALUE);
            break;
        default:
            break;       
    }
}

void Stage::handleWidgetSelectEvent(const Event &e)
{

}

void Stage::handleSceneSelectEvent(const Event &e)
{

}
