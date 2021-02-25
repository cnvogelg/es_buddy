#ifndef WIDGET_H
#define WIDGET_H

#include "drawable.h"
#include "event.h"

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

    int x() const { return pos.x; }
    int y() const { return pos.y; }
    int w() const { return size.w; }
    int h() const { return size.h; }

    int x2() const { return pos.x + size.w - 1; }
    int y2() const { return pos.y + size.h - 1; }
};

enum class ControlEvent {
    INC_VALUE,
    DEC_VALUE,
    ACTIVATE
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

class Control {
public:
    virtual void handleEvent(const ControlEvent &e) = 0;
    virtual Widget *getWidget() = 0;

    void setShowAlways(bool show) {
        _showAlways = show;
    }
    bool getShowAlways() {
        return _showAlways;
    }

protected:
    bool _showAlways = false;

};

#endif // WIDGET_H
