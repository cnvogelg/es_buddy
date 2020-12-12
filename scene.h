#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "drawable.h"
#include "widget.h"

class Scene
{
public:
    Scene(const char *name, const std::vector<Widget *> &widgets)
    : _name(name), _widgets(widgets) 
    {
        setDefaultActiveWidget();
    }

    const char *getName() { return _name; }
    Widget *getActiveWidget() { return _activeWidget; }

    virtual void enterScene();
    virtual void draw(Drawable &d);
    virtual void leaveScene();

protected:
    const char *_name;
    const std::vector<Widget *> _widgets;
    Widget *_activeWidget;

    void setDefaultActiveWidget();
};

#endif
