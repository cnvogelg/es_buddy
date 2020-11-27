#ifndef SCENE_H
#define SCENE_H

#include "drawable.h"

class Scene
{
public:
    virtual void enterScene() {}
    virtual void draw(Drawable &d) {}
    virtual void leaveScene() {}
};

#endif
