#pragma once

const std::string WRONG_CODE_MESSAGE = "Wrong code\n";

template <typename T>
class ProtectedValue
{
private:
    const T value;
    const size_t code;
public:
    ProtectedValue(const T& initValue, size_t initCode) : value(initValue), code(initCode)
    {}

    T getValue(size_t _code) const
    {
        if(code == _code)
        {
            return value;
        }
        throw std::invalid_argument(WRONG_CODE_MESSAGE);
    }

};
