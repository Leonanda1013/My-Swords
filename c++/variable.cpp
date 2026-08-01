#include <iostream>

int main(){
    int a = 10;
    int b = 20;
    int c;
    std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;
    c = b;
    b = a;
    a = c;
    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;
    return 0;
}