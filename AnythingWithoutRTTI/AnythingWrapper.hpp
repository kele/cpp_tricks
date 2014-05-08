#pragma once

template<class T>
class AnythingWrapper
{
public:
    AnythingWrapper(T& value)
        : m_value(value)
    {}

    T& value() const
    {
        return m_value;
    }

private:
    T& m_value;
};
