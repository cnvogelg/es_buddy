#include <Arduino.h>
#include "stage.h"

Stage::Stage(Display &display, EventSource &eventSource, 
    const std::vector<Scene *> &scenes, 
    int frame_ms)
    : _renderer(display, frame_ms),
        _eventSource(eventSource),
        _scenes(scenes),
        _inputState(WIDGET_NORMAL),
        _selectedSceneParam(0, 0, scenes.size() - 1, 1),
        _selectedSceneControl(getSceneSelectGeo(display), "sc:", &_selectedSceneParam)
{
    for(Scene *s : scenes) {
        s->setExtraControl(&_selectedSceneControl);
    }
    _selectedSceneParam.setMapper([=](int idx)->const char * { return this->getSceneName(idx); });
    _selectedSceneParam.setSetter([=](int idx) { this->changeActiveScene(idx); });

    _renderer.setDebug(true);

    // enter active scene
    _activeScene = getActiveScene();
    if(_activeScene != nullptr) {
        _activeScene->enterScene();
    }
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

void Stage::setActiveScene(int num)
{
    _selectedSceneParam.setValue(num);
}

void Stage::changeActiveScene(int num)
{
    // leave old scene
    Scene *oldScene = _activeScene;
    _activeScene = getActiveScene();

    if(oldScene != _activeScene) {
        if(oldScene != nullptr) {
            oldScene->leaveScene();
        }

        // new active scene
        if(_activeScene != nullptr) {
            _activeScene->enterScene();
        }
    }
}

void Stage::handle() 
{
    Scene *activeScene = getActiveScene();

    Event e;
    if(_eventSource.pollEvent(e)) {
        Serial.print("ev:");
        Serial.println((int)e.type);
        switch(_inputState) {
            case WIDGET_NORMAL:
                handleWidgetNormalEvent(activeScene, e);
                break;
            case WIDGET_SELECT:
                handleWidgetSelectEvent(activeScene, e);
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
        case EventType::BUTTON_UP:
            // leave and select widget
            _inputState = WIDGET_SELECT;
            _renderer.setBlink(true);
            break;
        default:
            break;       
    }
}

void Stage::handleWidgetSelectEvent(Scene *scene, const Event &e)
{
    if(scene == nullptr) {
        return;
    }

    switch(e.type) {
        case EventType::INC_VALUE:
            scene->selectNextControl();
            break;
        case EventType::DEC_VALUE:
            scene->selectPrevControl();
            break;
        case EventType::BUTTON_UP:
            // leave and select widget
            _inputState = WIDGET_NORMAL;
            _renderer.setBlink(false);
            break;
        default:
            break;       
    }
}
