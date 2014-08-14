#include <iostream>
#include <memory>

// NOTE this was an inconclusive test :(
//
class Parent {
public:
    char x;
    Parent(char x = 'p') : x(x) {}
    virtual void dump() {std::cout << "Parent:" << x << std::endl;}
};

class Child: public Parent {
    char y;
public:
    Child(char x = 'c') : Parent(x), y('y') {}
    void dump() {std::cout << "Child:" << x << std::endl;}
};

int main() {
    {
        std::cout << "===shared_ptr polymorphic===" << std::endl;
        auto parent = std::shared_ptr<Parent>(new Parent('p'));
        auto child = std::shared_ptr<Child>(new Child('c'));
        parent = child;
        parent->dump();
        child->dump();

    }
    {
        std::cout << "===shared_ptr& implicit polymorphic===" << std::endl;
        auto child = std::shared_ptr<Child>(new Child('c'));
        // invalid initialization of reference (requires a const):
        // std::shared_ptr<Parent>& badParent = child;
        const std::shared_ptr<Parent>& parent = child;
        parent->dump();
        child->dump();
        std::shared_ptr<Parent> parent2 = std::move(parent);
        parent2->dump();
    }
    return 0;
}
