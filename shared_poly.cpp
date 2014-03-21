#include <iostream>
#include <memory>

class Parent {
    public:
    char x = 'p';
};
class Child : public Parent {
    public:
    char x = 'c';
};

int main() {
    auto parent = std::shared_ptr<Parent>(new Parent);
    auto child = std::shared_ptr<Child>(new Child);
    std::cout << "===Initially===" << std::endl;
    std::cout << parent->x << std::endl;
    std::cout << child->x << std::endl;
    std::cout << "===Implicit Polymorphic===" << std::endl;
    parent = child;
    std::cout << parent->x << std::endl;
    std::cout << child->x << std::endl;
    std::cout << "===Explicit Polymorphic===" << std::endl;
    parent = std::dynamic_pointer_cast<Parent>(child);
    std::cout << parent->x << std::endl;
    std::cout << child->x << std::endl;
    std::cout << "===Non-polymorphic===" << std::endl;
    auto parent2 = std::shared_ptr<Parent>(new Parent);
    parent2->x = 'b';
    parent = parent2;
    std::cout << parent->x << std::endl;
    std::cout << parent2->x << std::endl;
    return 0;
}
