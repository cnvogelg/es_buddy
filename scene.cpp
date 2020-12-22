#include <Arduino.h>
#include "scene.h"

void Scene::enterScene()
{
    for(Widget *w : _widgets) {
        w->init();
    }
}

void Scene::draw(Drawable &d, bool allowHilite)
{
    for(Widget *w : _widgets) {
        bool hilite = (w == _activeWidget) && allowHilite;
        w->draw(d, hilite);
    }

    if(_extraWidget != nullptr) {
        _extraWidget->draw(d, allowHilite);
    }
}

void Scene::leaveScene()
{   
    for(Widget *w : _widgets) {
        w->exit();
    }
}

void Scene::setDefaultActiveWidget()
{
    _activeWidget = nullptr;
    for(Widget *w : _widgets) {
        if(w->getControl() != nullptr) {
            _activeWidget = w;
            break;
        }
    }
}

void Scene::handleEvent(const ControlEvent &e)
{
    if(_activeWidget != nullptr) {
        Control *c = _activeWidget->getControl();
        if(c != nullptr) {
            c->handleEvent(e);
        }
    }
}
