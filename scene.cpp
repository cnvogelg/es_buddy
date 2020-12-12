#include <Arduino.h>
#include "scene.h"

void Scene::enterScene()
{
    for(Widget *w : _widgets) {
        w->init();
    }
}

void Scene::draw(Drawable &d)
{
    for(Widget *w : _widgets) {
        bool hilite = (w == _activeWidget);
        w->draw(d, hilite);
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
