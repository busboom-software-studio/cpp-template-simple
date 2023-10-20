#include "hello.h"
#include <iostream>

void hello(std::string const& name) { 
    std::string hello_str = "Hello, ";
    std::cout << hello_str << name << "!\n"; 
}
