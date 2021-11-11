#include <iostream>
#include <string>

#include "basic/max.hpp"

int main() {
    int i = 42;

    std::cout << "max(7, i): " << Basic::max(7, i) << std::endl;

    double f1 = 3.4;
    double f2 = -6.7;
    std::cout << "max(f1, f2): " << Basic::max(f1, f2) << std::endl;

    std::string s1 = "mathematics";
    std::string s2 = "math";
    std::cout << "max(s1, s2): " << Basic::max(s1, s2) << std::endl;

    return 0;
}