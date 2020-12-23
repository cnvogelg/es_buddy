#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "drawable.h"
#include "widget.h"
#include "esb_param.h"

class Scene
{
public:
    Scene(const char *name, const std::vector<Widget *> &widgets,
        const std::vector<Control *> &controls);

    const char *getName() { return _name; }
    Widget *getActiveWidget() { return _activeWidget; }
    void setExtraControl(Control *c) { _extraControl = c; }

    virtual void enterScene();
    virtual void draw(Drawable &d, bool allowHilite=true);
    virtual void leaveScene();

    virtual bool handleEvent(const ControlEvent &e);

    Control *getActiveControl();
    void selectPrevControl();
    void selectNextControl();

protected:
    const char *_name;
    const std::vector<Widget *> _widgets;
    const std::vector<Control *> _controls;
    IntRangeParam _selectedControlParam;
    Widget *_activeWidget;
    Control *_extraControl;
};

#endif
