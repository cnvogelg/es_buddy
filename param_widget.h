#ifndef PARAM_WIDGET_H
#define PARAM_WIDGET_H

#include "text_widget.h"
#include "param.h"

template<typename Scalar>
class ScalarParamWidget : public TextWidget
{
public:
    ScalarParamWidget(const Geo &geo, const char *title,
        ScalarParam<Scalar> *param)
    : TextWidget(geo, title), _param(param)
    {}

protected:
    ScalarParam<Scalar> *_param;

    void printText(Print &p) 
    {
        TextWidget::printText(p);
        p.print(_param->getValue());
    }
};

using IntParamWidget = ScalarParamWidget<int>;
using FloatParamWidget = ScalarParamWidget<float>;

#endif