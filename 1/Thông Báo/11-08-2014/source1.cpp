#include<iostream>
#include<conio.h>

using namespace std;

class A
{
public:
	// default constructor
	A()
	{
		cout<<"Constructor parent!"<<endl;
	}
	// 3-parameter constructor
	A(int a, int b, int c)
	{
		cout<<"Constructor parent!"<<endl;
	}

	// destructor
	~A()
	{
		cout<<"Destructor parent!"<<endl;
	}
};

class B: public A 
{
public:
	// This call A default constructor function.
	// But A has no default constructor, so this will raise error
	B() // B(): A()
	{
		cout<<"Constructor child!"<<endl;
	}
	// This call 3-parameter constructor of A.
	B(int a, int b, int c):A(a,b,c)
	{
		cout<<"Constructor child!"<<endl;
	}	

	// destructor
	~B()
	{
		cout<<"Destructor child!"<<endl;
	}
};

void F()
{
	//B* x=new B(1,2,4);
	A* x=new B(1,2,4);
	
	delete x;
	x=NULL;
}

int main()
{	
	F();

	getch();
	return 0;
}