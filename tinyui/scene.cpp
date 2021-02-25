#include <Arduino.h>
#include "scene.h"

Scene::Scene(const char *name, const std::vector<Widget *> &widgets,
    const std::vector<Control *> &controls)
: _name(name), _widgets(widgets), _controls(controls),
  _selectedControlParam(0, 0, controls.size(), 1)
{
}

Control *Scene::getActiveControl()
{
    int index = _selectedControlParam.getValue();
    if(index == (int)_controls.size()) {
        return _extraControl;
    }
    if(_controls.empty()) {
        return nullptr;
    }
    return _controls[index];
}

void Scene::selectPrevControl()
{
    _selectedControlParam.decValue(1, true);
    Serial.print("ctrl-:");
    Serial.println(_selectedControlParam.getValue());
}

void Scene::selectNextControl()
{
    _selectedControlParam.incValue(1, true);
    Serial.print("ctrl+:");
    Serial.println(_selectedControlParam.getValue());
}

void Scene::enterScene()
{
    Serial.print("enter:");
    Serial.println(getName());
    for(Widget *w : _widgets) {
        w->init();
    }
    for(Control *c : _controls) {
        c->getWidget()->init();
    }
}

void Scene::draw(Drawable &d, bool allowHilite, bool showControls)
{
    preDraw();

    for(Widget *w : _widgets) {
        if(w->isVisible(showControls)) {
            w->draw(d, false);
        }
    }

    Control *activeControl = getActiveControl();
    for(Control *c : _controls) {
        Widget *w = c->getWidget();
        if(w->isVisible(showControls)) {
            bool hilite = (activeControl == c) && allowHilite;
            w->draw(d, hilite);
        }
    }

    if(_extraControl != nullptr) {
        Widget *w = _extraControl->getWidget();
        if(w->isVisible(showControls)) {
            bool hilite = (activeControl == _extraControl) && allowHilite;
            w->draw(d, hilite);
        }
    }
}

void Scene::leaveScene()
{   
    Serial.print("leave:");
    Serial.println(getName());
    for(Widget *w : _widgets) {
        w->exit();
    }
    for(Control *c : _controls) {
        c->getWidget()->exit();
    }
}

bool Scene::handleEvent(const ControlEvent &e)
{
    Control *activeControl = getActiveControl();
    if(activeControl != nullptr) {
        activeControl->handleEvent(e);
        return true;
    } else {
        return false;
    }
}
