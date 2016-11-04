#pragma once
#include "a.h"

class B : public A {     // define derived class B
public:
	B(int x, int y);     // overloading constructor
	B(const B& other);   // overloading constructor
	B();                 // "default" constructor
	~B(void);            // destructor
	int bar;             // declare int type member bar
};
