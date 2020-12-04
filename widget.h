#ifndef WIDGET_H
#define WIDGET_H

#include "drawable.h"

struct Pos {
    int x,y;
};

struct Size {
    int w,h;
};

struct Geo {
    Pos  pos;
    Size size;

    Geo(const Pos &pos_, const Size &size_)
    : pos(pos_), size(size_) {}

    Geo(int x, int y, int w, int h)
    : pos{x,y}, size{w,h} {}

    int x() { return pos.x; }
    int y() { return pos.y; }
    int w() { return size.w; }
    int h() { return size.h; }

    int x2() { return pos.x + size.w - 1; }
    int y2() { return pos.y + size.h - 1; }
};

class Widget {
public:
    Widget(const Geo &geo)
        : _geo(geo)
    {}

    virtual void init() {}
    virtual void draw(Drawable &d, bool hilite) = 0;
    virtual void exit() {}

protected:
    Geo _geo;

    void drawBorder(Drawable &d) {
        d.drawRect(_geo.x(), _geo.y(), _geo.w(), _geo.h());
    }
    void fillWidget(Drawable &d) {
        d.fillRect(_geo.x(), _geo.y(), _geo.w(), _geo.h());
    }

    void setBackColor(Drawable &d) { d.setColor(COLOR_BLACK); }
    void setHiliteColor(Drawable &d) { d.setColor(COLOR_YELLOW); }
    void setNormalColor(Drawable &d) { d.setColor(COLOR_WHITE); }
};

#endif // WIDGET_H
