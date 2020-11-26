#ifndef DRAWABLE_H
#define DRAWABLE_H

// BGR 565
#define COLOR_RGB(r,g,b) ((r)<<11 | (g)<<5 | (b)) 
#define COLOR_MAX_RED   31
#define COLOR_MAX_GREEN 63
#define COLOR_MAX_BLUE  31

#define COLOR_RED           COLOR_RGB(0,0,COLOR_MAX_RED)
#define COLOR_BLUE          COLOR_RGB(COLOR_MAX_BLUE,0,0)
#define COLOR_GREEN         COLOR_RGB(0,COLOR_MAX_GREEN,0)

#define COLOR_WHITE         0xFFFF
#define COLOR_GRAY          COLOR_RGB(15,31,15)
#define COLOR_BLACK         0

class Drawable {
public:
    virtual void homeCursor() = 0;
    virtual void setCursor(int x, int y) = 0;
    virtual int getMaxCursorX() = 0;
    virtual int getMaxCursorY() = 0;
    virtual Print &getPrint() = 0;

    virtual void setTextColor(uint16_t fg, uint16_t bg);
    virtual void setTextColor(uint16_t fg);
    virtual void setTextSize(uint8_t sx, uint8_t sy);

    virtual void setColor(uint16_t color) = 0;
    virtual void line(int x1, int y1, int x2, int y2) = 0;
    virtual void vline(int x, int y, int h) = 0;
    virtual void hline(int x, int y, int w) = 0;
    virtual void pixel(int x, int y) = 0;
};

class Display : public Drawable {
public:
    virtual void displayClear() = 0;
    virtual void displayUpdate() = 0;
};

#endif
