#pragma once

#include "TypeIdentification.hpp"

#include <cassert>

class Anything
{
public:
    template<class T>
    Anything(const T& value)
        : m_value(new ValueContainer<T>(value))
    {}

   
    template<class T>
    const T& value() const
    {
        assert(TypeIdentification<T>::getTypeId() == m_value->typeId());
        return static_cast< ValueContainer<T>* >(m_value)->value;
    }

    template<class T>
    bool isType() const
    {
        return TypeIdentification<T>::getTypeId() == m_value->typeId();         
    }

    ~Anything()
    {
        delete m_value;
    }

protected:
    struct BaseValueContainer
    {
    public:
        virtual TypeIdentificator typeId() const = 0;
        virtual ~BaseValueContainer() {}
    };

    template<class T>
    struct ValueContainer : public BaseValueContainer
    {
        ValueContainer(const T& value)
            : value(value)
        {}

        TypeIdentificator typeId() const
        {
            return TypeIdentification<T>::getTypeId();
        }

        const T& value;
    };

    BaseValueContainer *m_value;
};

