#include <iostream>
#include "hello.hpp"

void hello::say_hello(){
    std::cout << "Hello, world!" << std::endl;
    std::cout << "VERSION :" << VERSION << std::endl;
}