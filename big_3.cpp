#include <iostream>

struct Big3Count {
    std::uint64_t construct=0;
    std::uint64_t destruct=0;
    std::uint64_t copy_construct=0;

    inline friend std::ostream& operator<<(std::ostream& out, const Big3Count& s) {
        out << "construct=" << s.construct << " destruct=" << s.destruct << " copy_construct=" << s.copy_construct << std::endl;
        return out;
    } 
};
Big3Count b3c;
struct Foo {
    char c;
    // constructor
    Foo() : c('!') {
        b3c.construct++;
    }
    // destructor
    ~Foo() {
        b3c.destruct++;
    }
    // copy constructor
    Foo(Foo& a) {
        b3c.copy_construct++;
    }
};

int main() {
    {
        b3c.construct = 0;
        Foo a;
        std::cout << b3c;
        {
            Foo b(a);
            std::cout << b3c;
        }
        std::cout << b3c;
    }
    std::cout << b3c;
    return 0;
}
