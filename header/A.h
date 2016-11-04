#pragma once
class A
{
public:
	A(int x);            // declare constructor
	A(const A& other);   // declare another constructor
	A();                 // declare "default" constructor
	virtual ~A(void);    // virtual destructor
	// ~A(void); // what happens if you don't make A virtual? Ans: the destructor of the base class will be called but not the one of the derived class, resulting in a resources leak
	int foo;             // declare int type member foo
};

