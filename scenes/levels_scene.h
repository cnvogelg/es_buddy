#ifndef LEVELS_SCENE_H
#define LEVELS_SCENE_H

#include "esb_tinyui.h"
#include "esb_param.h"
#include "esb_widgets.h"
#include "audio/analyze_minmax.h"

class LevelsScene : public Scene
{
public:
    LevelsScene(Display &d) :
        Scene("Levels",
            { &_minValWidget, &_maxValWidget,
              &_minVoltWidget, &_maxVoltWidget,
              &_peakValWidget },
            {}),
        _minValParam(0.0f, -1.0f, 1.0f, 0.1f),
        _maxValParam(0.0f, -1.0f, 1.0f, 0.1f),
        _minVoltParam(0.0f, -10.0f, 10.0f, 1.0f, " V"),
        _maxVoltParam(0.0f, -10.0f, 10.0f, 1.0f, " V"),
        _peakValParam(0.0f, 0.0f, 1.0f, 0.1f),
        _dbParam(0.0f, 0.0f, 1.0f, 0.1f),
        _minValWidget(Geo(0,0,64,12), "min=", &_minValParam),
        _maxValWidget(Geo(0,12,64,12), "max=", &_maxValParam),
        _minVoltWidget(Geo(0,24,64,12), "min=", &_minVoltParam),
        _maxVoltWidget(Geo(0,36,64,12), "max=", &_maxVoltParam),
        _peakValWidget(Geo(0,48,160,12), _peakValParam, true),
        _dbWidget(Geo(0,60,160,12), _dbParam, true)
    {
        _minVoltParam.setGetter([=]()->int{ return _minValParam.getValue() * 10.0f; });
        _maxVoltParam.setGetter([=]()->int{ return _maxValParam.getValue() * 10.0f; });
    }

    void preDraw(void) 
    {
        float min, max;
        _analyzeMinMax.read(min, max);
        _minValParam.setValue(min);
        _maxValParam.setValue(max);
        float peak = max - min;
        _peakValParam.setValue(peak);
    }

    AudioStream &getAudioInput() { return _analyzeMinMax; }

protected:
    AudioAnalyzeMinMax      _analyzeMinMax;
    FloatRangeParam         _minValParam;
    FloatRangeParam         _maxValParam;
    FloatRangeParam         _minVoltParam;
    FloatRangeParam         _maxVoltParam;
    FloatRangeParam         _peakValParam;
    FloatRangeParam         _dbParam;
    FloatTextParamWidget    _minValWidget;
    FloatTextParamWidget    _maxValWidget;
    FloatTextParamWidget    _minVoltWidget;
    FloatTextParamWidget    _maxVoltWidget;
    BarWidget               _peakValWidget;
    BarWidget               _dbWidget;
};

#endif
