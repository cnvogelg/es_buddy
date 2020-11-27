#ifndef WIDGET_H
#define WIDGET_H

#include "drawable.h"

class Widget {
public:
    Widget(int x, int y, int w, int h)
        : _x(x), _y(y), _w(w), _h(h)
    {}

    virtual void init() {}
    virtual void draw(Drawable &d) = 0;
    virtual void exit() {}

protected:
    int _x, _y, _w, _h;

    void drawBorder(Drawable &d) {
        d.vline(_x, _y, _h);
        d.vline(_x + _w - 1, _y, _h);
        d.hline(_x, _y, _w);
        d.hline(_x, _y + _h - 1, _w);
    }
};

#endif // WIDGET_H
