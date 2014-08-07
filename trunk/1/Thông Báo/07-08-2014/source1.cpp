#include<iostream>

using namespace std;

class A
{
public:
	// default constructor
	A()
	{

	}
	// 3-parameter constructor
	A(int a, int b, int c)
	{

	}
};

class B: public A 
{
public:
	// This call A default constructor function.
	// But A has no default constructor, so this will raise error
	B() // B(): A()
	{

	}
	// This call 3-parameter constructor of A.
	B(int a, int b, int c):A(a,b,c)
	{

	}	
};

int main()
{
	
	return 0;
}