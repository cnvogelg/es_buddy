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

    void setMapper(std::function<const char*(Type)> mapper)
    {
        _mapper = mapper;
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

    bool setValue(Type value)
    {
        _value = value;
        if(_setter) {
            _setter(value);
        }
        return true;
    }

    void setDefaultValue() 
    {
        setValue(_defaultValue);
    }

    const char *getMappedValue() {
        if(_mapper) {
            return _mapper(_value);
        }
        else {
            return nullptr;
        }
    }

protected:
    Type _defaultValue;
    Type _value;
    const char *_unitsStr;

    std::function<void(Type)> _setter;
    std::function<Type(void)> _getter;
    std::function<const char *(Type)> _mapper;
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

    bool setValue(Scalar value) {
        if((value >= _minValue) && (value <= _maxValue)) {
            Param<Scalar>::setValue(value);
            return true;
        } else {
            return false;
        }
    }

    bool incValue(int num=1) {
        Scalar value = this->getValue() + (_step * num);
        if(value > _maxValue) {
            value = _maxValue;
        }
        return setValue(value);
    }

    bool decValue(int num=1) {
        Scalar value = this->getValue() - (_step * num);
        if(value < _minValue) {
            value = _minValue;
        }
        return setValue(value);
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