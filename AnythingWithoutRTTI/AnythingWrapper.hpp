#pragma once

template<class T>
struct AnythingWrapper
{
public:
    AnythingWrapper(T& value)
        : value(value)
    {}

    T& value;
};
