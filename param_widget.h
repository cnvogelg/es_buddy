#ifndef PARAM_WIDGET_H
#define PARAM_WIDGET_H

#include "text_widget.h"
#include "param.h"

template<typename Scalar>
class TextParamWidget : public TextWidget
{
public:
    TextParamWidget(const Geo &geo, const char *title,
        Param<Scalar> *param)
    : TextWidget(geo, title), _param(param)
    {}

protected:
    Param<Scalar> *_param;

    void printText(Print &p) 
    {
        TextWidget::printText(p);
        p.print(_param->getValue());
        const char *units = _param->getUnitsString();
        if(units!=nullptr) {
            p.print(units);
        }
    }
};

template<typename Scalar>
class TextParamControl : public TextParamWidget<Scalar>, public Control
{
public:
    TextParamControl(const Geo &geo, const char *title,
        RangeParam<Scalar> *param)
    : TextParamWidget<Scalar>(geo, title, param),
      _rangeParam(param)
    {}

    virtual void handleEvent(const ControlEvent &ce) {
        switch(ce) {
            case ControlEvent::INC_VALUE:
                _rangeParam->incValue();
                break;
            case ControlEvent::DEC_VALUE:
                _rangeParam->decValue();
                break;
        }
    }

protected:
    RangeParam<Scalar> *_rangeParam;
};

using IntTextParamWidget = TextParamWidget<int>;
using FloatTextParamWidget = TextParamWidget<float>;
using IntTextParamControl = TextParamControl<int>;
using FloatTextParamControl = TextParamControl<float>;

#endif