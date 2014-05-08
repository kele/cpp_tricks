#pragma once

typedef void (*TypeIdentificator)();

template<class T>
class TypeIdentification
{
public:
    static TypeIdentificator getTypeId()
    {
        return &magicMethod;
    }

private:
    static void magicMethod() {}
};


