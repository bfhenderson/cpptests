#include <memory>
#include <iostream>

void foo(std::unique_ptr<int>& a) {
    std::cout << *a << std::endl;
}

int main() {
    auto a = std::unique_ptr<int>(new int(1));
    std::cout << *a << std::endl;
    foo(a);
    std::cout << *a << std::endl;
    return 0;
}
