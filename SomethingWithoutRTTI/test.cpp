#include "Anything.hpp"
#include "AnythingWrapper.hpp"
#include "TypeIdentification.hpp"

#include <iostream>
#include <boost/ref.hpp>
#include <boost/noncopyable.hpp>


enum ETestEnum
{
    ESomething1,
    ESomething2
};

enum EUnknownEnum
{
    ESomethingUnknown
};

class Env : public boost::noncopyable
{
public:
    Env() { x = 0; }
    void changeSomething()
    {
        std::cout << x++;
    }

    int x;
};

void foo(const Anything &arg)
{
    if (arg.isType<int>())
    {
        std::cout << "int";
    }
    else if (arg.isType<double>())
    {
        std::cout << "double"; 
    }
    else if (arg.isType< AnythingWrapper<Env> >())
    {
        std::cout << "AnythingWrapper<Env>: ";

        Env &env = arg.value< AnythingWrapper<Env> >().value();
        env.changeSomething();
        env.changeSomething();
        env.changeSomething();
        env.changeSomething();
    }
    else if (arg.isType<ETestEnum>())
    {
        std::cout << "ETestEnum";
    }
    else
    {
        std::cout << "Unkown type!";
    }
    std::cout << "\n";
}

int main()
{    
    int x;
    foo(1);
    foo(1.2);
    foo(x);

    Env e;
    foo(AnythingWrapper<Env>(e));
    foo(AnythingWrapper<Env>(e));

    foo(ESomething1);
    foo(ESomething2);
    foo(ESomethingUnknown);

    std::cout << "\nsizeofs\n";
    std::cout << "AnythingWrapper<Env> = " << sizeof(AnythingWrapper<Env>) << std::endl;
    std::cout << "Env = " << sizeof(Env) << std::endl;
    std::cout << "Anything = " << sizeof(Anything) << std::endl;
}
