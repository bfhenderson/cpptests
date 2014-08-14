#include <memory>
#include <iostream>

class B {
    public:
    char x = 'x';
};

class A {
    public:
    B the_b;
    B* ptr_b;
    std::shared_ptr<B> shp_b;
    void alterB(char x) {
        the_b.x = x;
    }
};

int main() {
    A a1;
    B b1;
    a1.ptr_b = &b1;
    a1.shp_b = std::shared_ptr<B>(new B);
    const A a2 = a1;
    //read-only error
    //a2.the_b.x = '0';
    // compiles just fine
    a2.ptr_b->x = '1';
    a2.shp_b->x = '2';
    // discard qualifier error
    //a2.alterB('3');
    return 0;
}
