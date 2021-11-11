#include <iostream>

#include "basic/smart_pointer.hpp"

class A {
public:
    A() {
        std::cout << "Invoke constructor of A" << std::endl;
    }

    virtual ~A() {
        std::cout << "Invoke destructor of A" << std::endl;
    }

    virtual void hello() {
        std::cout << "Hello smart pointer of A" << std::endl;
    }
};

class B : public A {
public:
    B() {
        std::cout << "Invoke constructor of B" << std::endl;
    }

    virtual ~B() {
        std::cout << "Invoke destructor of B" << std::endl;
    }

    virtual void hello() {
        std::cout << "Hello smart pointer of B" << std::endl;
    }
};

void invoke_in_scope() {
    Basic::unique_pointer<B> sp(new B);
    sp->hello();

    // auto sp1 = sp;
    Basic::unique_pointer<A> sp1 = std::move(sp);

    Basic::unique_pointer<A> sp2;

    sp2 = std::move(sp1);
    sp2->hello();
}


int main() {
    std::cout << "Starting..." << std::endl;
    invoke_in_scope();
    std::cout << "Stopping..." << std::endl;
    return 0;
}
