#include <Arduino.h>
#include "text_widget.h"

void TextWidget::draw(Drawable &d, bool hilite)
{
    setBackColor(d);
    fillWidget(d);

    int x_off = 2;
    int y_off = 2; 
    d.setCursorXY(_geo.x() + x_off, _geo.y() + y_off);
    printText(d.getPrint());

    if(hilite) {
        setHiliteColor(d);
        drawBorder(d);
    }
}
