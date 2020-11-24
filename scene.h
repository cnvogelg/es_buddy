#ifndef SCENE_H
#define SCENE_H

#include "drawable.h"

class Scene
{
public:
    virtual bool preDraw() { return true; }
    virtual void draw(Drawable &d) {}
    virtual void postDraw(bool did_draw) {}

    virtual void enterScene() {}
    virtual void leaveScene() {}
};

#endif
