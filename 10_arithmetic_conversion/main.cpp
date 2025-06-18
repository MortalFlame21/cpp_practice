#include <iostream>
#include <typeinfo>
#include <type_traits>

class test { };

int main(int argc, char* argv[]) {
    int i{ 2 };
    std::cout << typeid(i).name() << '\n';
    double d{ 3.5 };
    std::cout << typeid(d).name() << '\n';
    std::cout << typeid(i + d).name() << ' ' << i + d << '\n';
    std::cout << "char + char = " << typeid('a' + 'a').name() << "\n";
  
    // std::cout << "class bro = " << typeid(test()) << "\n";
    // ^ wont work cause it needs operator<< type thing
}