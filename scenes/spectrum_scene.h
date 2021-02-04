#ifndef SPECTRUM_SCENE_H
#define SPECTRUM_SCENE_H

#include "esb_tinyui.h"
#include "esb_widgets.h"

class SpectrumScene : public Scene
{
public:
    SpectrumScene(Display &d) :
        Scene("Spectrum",
            { &_spectrumWidget, &_gridUnitWidget },
            { &_windowSizeWidget }),
        _spectrumWidget(Geo(0, 0, d.getDisplayWidth(), d.getDisplayHeight())),
        _windowSizeParam(1, 1, 64, 1),
        _windowSizeWidget(Geo(0,0,64,12), "win=", &_windowSizeParam),
        _gridUnitMsParam(1, " ms"),  
        _gridUnitWidget(Geo(0,12,64,12), "grid=", &_gridUnitMsParam)
    {
    }

    SpectrumWidget &getSpectrumWidget() { return _spectrumWidget; }
    AudioStream &getAudioInput() { return _spectrumWidget.getAudioInput(); }

protected:
    SpectrumWidget          _spectrumWidget;
    IntRangeParam           _windowSizeParam;
    IntTextParamControl     _windowSizeWidget;
    IntParam                _gridUnitMsParam;
    IntTextParamWidget      _gridUnitWidget;
};

#endif
