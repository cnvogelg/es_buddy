#ifndef BAR_WIDGET_H
#define BAR_WIDGET_H

#include "tinyui/widget.h"
#include "esb_param.h"

class BarWidget : public Widget
{
public:
    BarWidget(const Geo &geo, FloatRangeParam &param, bool horiz)
    : Widget(geo), _param(param), _horiz(horiz)
    {}

    virtual void draw(Drawable &d, bool hilite);

protected:
    FloatRangeParam &_param;
    bool _horiz;
};

#endif
