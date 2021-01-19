#include <Arduino.h>
#include "bar_widget.h"

void BarWidget::draw(Drawable &d, bool hilite)
{
    setBackColor(d);
    fillWidget(d);
    if(hilite) {
        setHiliteColor(d);
    } else {
        setNormalColor(d);
    }
    drawBorder(d);

    float val = _param.getNormalizedValue();
    
    int w = _geo.w() - 2;
    int h = _geo.h() - 2;
    int x = _geo.x() + 1;
    int y = _geo.y() + 1;
    if(_horiz) {
        int ws = (int)(w * val);
        for(int i=0;i<ws;i++) {
            d.vline(x, y, h);
            x++;
        }
    } else {
        int hs = (int)(h * val);
        for(int i=0;i<hs;i++) {
            d.hline(x, y, w);
            y++;
        }
    }
}
