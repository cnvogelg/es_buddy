#ifndef SCOPE_SCENE_H
#define SCOPE_SCENE_H

#include "esb_tinyui.h"
#include "esb_widgets.h"

class ScopeScene : public Scene
{
public:
    ScopeScene(Display &d) :
        Scene("Scope",
            { &_scopeWidget, &_gridUnitWidget },
            { &_windowSizeWidget }),
        _scopeWidget(Geo(0, 0, d.getDisplayWidth(), d.getDisplayHeight())),
        _windowSizeParam(1, 1, 64, 1),
        _windowSizeWidget(Geo(0,0,64,12), "win=", &_windowSizeParam),
        _gridUnitMsParam(1, " ms"),  
        _gridUnitWidget(Geo(0,12,64,12), "grid=", &_gridUnitMsParam)
    {
        _gridUnitWidget.setShowMode(Widget::SHOW_CONTROL);
        _windowSizeParam.setSetter([=](int value){ _scopeWidget.setWindowSize(value); });
        _windowSizeParam.setGetter([=]()->int{ return _scopeWidget.getWindowSize(); });
        _gridUnitMsParam.setGetter([=]()->int{ return _scopeWidget.getGridUnitMs(); });
    }

    AudioStream &getAudioInputX() { return _scopeWidget.getAudioInputX(); }
    AudioStream &getAudioInputY() { return _scopeWidget.getAudioInputY(); }

protected:
    ScopeWidget             _scopeWidget;
    IntRangeParam           _windowSizeParam;
    IntTextParamControl     _windowSizeWidget;
    IntParam                _gridUnitMsParam;
    IntTextParamWidget      _gridUnitWidget;
};

#endif
