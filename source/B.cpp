#include "B.h"
#include <iostream>

B::B(int x, int y) : A(x), bar(y) { std::cout << __FUNCTION__ << std::endl; }  // define the constructor | action: print out the undecorated name of the enclosing function

B::B(const B& other) { std::cout << __FUNCTION__ << std::endl; }               // define the constructor

B::B() : A() { std::cout << __FUNCTION__ << std::endl; }                       // define the constructor

B::~B(void)                                                                    // define the destructor
{
	std::cout << __FUNCTION__ << std::endl;
}
