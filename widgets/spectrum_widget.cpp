#include <Arduino.h>
#include "scope_widget.h"

void SpectrumWidget::init()
{
}

void SpectrumWidget::exit()
{
}

void SpectrumWidget::draw(Drawable &d, bool hilite)
{
    float range = (_maxHz - _minHz) / _maxHz;
    float baseFactor = 1.0f / 3.321f;
    _xLogFactor = 1.0f - (1.0f - baseFactor) * range;

    drawGrid(d);
    drawBins(d);
    if(hilite) {
        setHiliteColor(d);
        drawBorder(d);
    }
}

void SpectrumWidget::drawGridX(Drawable &d)
{
    // log10(x) range
    float hz = 100.0f;
    while(hz < _maxHz && hz < 1001.0f) {
        drawGridXLine(d, hz);
        hz += 100.0f;
    }
    hz = 2000.0f;
    while(hz < _maxHz && hz < 10001.0f) {
        drawGridXLine(d, hz);
        hz += 1000.0f;
    }
    hz = 20000.0f;
    while(hz < _maxHz && hz < 100001.0f) {
        drawGridXLine(d, hz);
        hz += 10000.0f;
    }

    // labels
    const float labelHz[] = { 100.0f, 1000.0f, 10000.0f };
    const char *labelStr[] = { "100", "1k", "10k" };
    for(int i=0;i<3;i++) {
        float hz = labelHz[i];
        if(hz < _maxHz) {
            int x = mapX(hz);
            if(x!=-1) {
                const char *str = labelStr[i];
                d.setCursorXY(x, _geo.y() - d.getFontHeight());
                d.getPrint().print(str);
            }
        }
    }
}

void SpectrumWidget::drawGridY(Drawable &d)
{
    int dbVals[] = { 12, 0, -12, -24, -48, -96 };
    for(int i=0;i<6;i++) {
        int db = dbVals[i];
        int y = mapYDb(db);
        if(y!=-1) {
            d.hline(_geo.x(), y, _geo.w());
            d.setCursorXY(_geo.x2() - d.getFontWidth() * 3, y);
            d.getPrint().print(db);
        }
    }
}

void SpectrumWidget::drawGrid(Drawable &d)
{
    d.setColor(COLOR_GRAY);
    drawBorder(d);
    drawGridX(d);
    drawGridY(d);
}

void SpectrumWidget::drawBins(Drawable &d)
{
    if(!_fft.available()) {
        return;
    }

    d.setColor(COLOR_GREEN);
    int lastX;
    int lastY;
    bool lastValid = false;
    float hzFac = 0.5;
    for(int i=0;i<_numBins;i++) {
        float mag = _fft.read(i);
        float hz = hzFac * _hzPerBin;
        float db = amplitudeToDecibels(mag);
        db = signal_clamp(db, _posDb - _rangeDb, _posDb);
        int x = mapX(hz);
        int y = mapYDb(db);
        if((x != -1) && (y != -1)) {
            if(lastValid) {
                d.vline(x, y, _geo.h() - y);
            }
            lastValid = true;
            lastX = x;
            lastY = y;
        } else {
            lastValid = false;
        }
        hzFac++;
    }   
}
