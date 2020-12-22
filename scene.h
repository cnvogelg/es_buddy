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
    void setExtraWidget(Widget *w) { _extraWidget = w; }

    virtual void enterScene();
    virtual void draw(Drawable &d, bool allowHilite=true);
    virtual void leaveScene();

    virtual void handleEvent(const ControlEvent &e);

protected:
    const char *_name;
    const std::vector<Widget *> _widgets;
    Widget *_activeWidget;
    Widget *_extraWidget;

    void setDefaultActiveWidget();
};

#endif
