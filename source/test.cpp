
/*
TestSlicing
(c) 2016
original authors: David I. Schwartz
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*	This tutorial illustrates the problem when using the virtual function called slicing.
*	It also covers the concept of constructor and destructor, predefined macros, and virtual function.
*/

/* Slicing:
 * Passing an object by value does not enable the virtual functions to be invoked.
 * http://www.devx.com/tips/Tip/14570
 * http://stackoverflow.com/questions/274626/what-is-the-slicing-problem-in-c
 *
 */
#include <iostream> // for cout
#include "A.h"      // include header files
#include "B.h"
using namespace std;// for cout

void main() {

	cout << "\nMake B object called test1: " << endl;  // output: Make B object called test1:
	B test1(100,200);                                  // define a B type object test1; assign 100 and 200 as its parameters | output: A::A
                                                       //                                                                         B::B
	cout << "Foo:  " << test1.foo << endl;             // output: Foo:  100
	cout << "Bar:  " << test1.bar << endl;             // output: Bar:  200

	/*
	cout << "\nA test2 = test1: " << endl;  // output: A test2 = test1:
	A test2 = test1;                        // define a A type object test2; assign test1 to it
	                                        // output: A::A
	                                        //         B::B
	cout << "Foo:  " << test2.foo << endl;  // output: Foo:  -858993460
	cout << "Bar:  " << test2.bar << endl;  // does this succeed? Ans: No. bar is not a member of 'A'
	*/

	/*
	cout << "\nA& test3 = test1: " << endl;  // output: A& test3 = test1:
	A& test3 = test1;                        // define a reference 'test3' to A type object; assign test1 to it
	                                         // output: A::A
	                                         //         B::B
	cout << "Foo:  " << test3.foo << endl;   // output: Foo:  100
	cout << "Bar:  " << test3.bar << endl;   // does this succeed? Ans: No. bar is not a  member of 'A'
	*/

	/*
	cout << "\nA* test4 = &test1: " << endl;  // output: A* test4 = &test1: 
	A* test4 = &test1;                        // define a pointer to a A type object; assign the address of test1 to it
	                                          // output: A::A
	                                          //         B::B
	cout << "Foo:  " << test4->foo << endl;   // output: Foo:  100
	cout << "Bar:  " << test4->bar << endl;   // does this succeed? Ans: No. bar is not a  member of 'A'
	*/

	/*
	cout << "\nA* test5 = new B(100,200): " << endl;          // output: A* test5 = new B(100,200): 
	A* test5 = new B(100,200);                                // Creating a pointer to Base class named A and then initializing it to B class, put 100 and 200 as its parameters
	                                                          // output: A::A
	                                                          //         B::B
	cout << "Foo:  " << test5->foo << endl;                   // output: Foo:	100
	cout << "Bar:  " << static_cast<B*>(test5)->bar << endl;  // output: Bar:	200
	cout << "Bar:  " << dynamic_cast<B*>(test5)->bar << endl; // dynamic safer? 
                                                              // Ans: Yes, because static_cast does no run-time type check, while dynamic_cast does  https://msdn.microsoft.com/en-us/library/c36yw7x9.aspx

	cout << "\nDelete test5: " << endl;                       // output: Delete test5: 
	delete test5;                                             // deallocation  | output: B::~B
    */                                                        //                         A::~A
	

	cout << "\nDelete everything else: " << endl;  // output: Delete everything else:
	                                               //         test1         test2         test3         test4         test5     
                                                   //         B::~B         A::~A         B::~B         B::~B         B::~B
	                                               //         A::~A         B::~B         A::~A         A::~A         A::~A
	                                               //                       A::~A
}