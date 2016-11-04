#include "../header/A.h"
#include <iostream>

A::A(int i) : foo(i) { std::cout << __FUNCTION__ << std::endl; }   // define constructor | action: print out the undecorated name of the enclosing function

A::A(const A& other) { std::cout << __FUNCTION__ << std::endl; }   // define another constructor

A::A() { std::cout << __FUNCTION__ << std::endl; }                 // define "default" constructor

A::~A(void)                                                        // define destructor
{
	std::cout << __FUNCTION__ << std::endl;                        
}
