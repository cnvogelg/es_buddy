#ifndef TEXT_WIDGET_H
#define TEXT_WIDGET_H

#include "widget.h"

class TextWidget : public Widget
{
public:
    TextWidget(const Geo &geo, const char *text)
    : Widget(geo), _text(text)
    {}

    virtual void draw(Drawable &d, bool hilite);

protected:
    const char *_text;
    
    virtual void printText(Print &p) {
        p.print(_text);
    }
};

#endif
