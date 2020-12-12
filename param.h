#ifndef PARAM_H
#define PARAM_H

#include <functional>

template<typename Type>
class Param
{
public:
    Param(Type defaultValue, const char *unitsStr=nullptr)
    : _defaultValue(defaultValue), _value(defaultValue),
      _unitsStr(unitsStr)
    {}
    
    void setSetter(std::function<void(Type)> setter)
    {
        _setter = setter;
    }

    void setGetter(std::function<Type(void)> getter)
    {
        _getter = getter;
    }

    void reset() { setValue(_defaultValue); }

    Type getDefaultValue() { return _defaultValue; }
    const char *getUnitsString() { return _unitsStr; }

    Type getValue() 
    {
        if(_getter) {
            _value = _getter();
        }
        return _value;
    }

    void setValue(Type value)
    {
        _value = value;
        if(_setter) {
            _setter(value);
        }
    }

protected:
    Type _defaultValue;
    Type _value;
    const char *_unitsStr;

    std::function<void(Type)> _setter;
    std::function<Type(void)> _getter;
};

template<typename Scalar>
class RangeParam : public Param<Scalar>
{
public:
    RangeParam(Scalar defaultValue, Scalar minValue, Scalar maxValue, Scalar step,
        const char *unitsStr=nullptr)
    : Param<Scalar>(defaultValue, unitsStr),
      _minValue(minValue), _maxValue(maxValue), _step(step)
    {}

    Scalar getMinValue() { return _minValue; }
    Scalar getMaxValue() { return _maxValue; }
    Scalar getStep() { return _step; }

    void setValue(Scalar value) {
        if((value >= _minValue) && (value <= _maxValue)) {
            Param<Scalar>::setValue(value);
        }
    }

    void incValue() {
        Scalar value = this->getValue() + _step;
        setValue(value);
    }

    void decValue() {
        Scalar value = this->getValue() - _step;
        setValue(value);
    }

protected:
    Scalar _minValue;
    Scalar _maxValue;
    Scalar _step;
};

using IntParam = Param<int>;
using FloatParam = Param<float>;
using IntRangeParam = RangeParam<int>;
using FloatRangeParam = RangeParam<float>;

#endif