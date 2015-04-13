#include <iostream>
#include <memory>

struct Real
{
    void foo() { std::cout << "foo" << std::endl; }
    void bar() { std::cout << "bar" << std::endl; }
    void baz() { std::cout << "baz" << std::endl; }
};

struct Wrapping
{
    struct Wrapper
    {

        Real* operator->()
        {
            return m_obj.get();
        }

        ~Wrapper()
        {
            std::cout << "Destroy!" << std::endl;
        }

    private:
        Wrapper()
            : m_obj(new Real)
        {
            std::cout << "New!" << std::endl;
        }

        Wrapper(Wrapper&& rhs)
            : m_obj(std::move(rhs.m_obj))
        {}

        std::unique_ptr<Real> m_obj;

        friend struct Wrapping;
    };

    Wrapper operator->()
    {
        return Wrapper();
    }
};


int main()
{
    Wrapping w;

    w->foo();
    w->bar();
    w->baz();
}
