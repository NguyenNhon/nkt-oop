#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

class A
{
private:
	char* s;
public:
	A()
	{
		s=new char[40];
		strcpy(s,"hoai sang");
	}

	~A()
	{
		delete[] s;
		s=NULL;
	}

	/*A(const A &a)
	{
		s=new char[strlen(a.s)+1];
		strcpy(s, a.s);
	}*/

	void Print()
	{
		cout<<s<<endl;
	}
};

// create new object of class A
void F(A thamso)
{
	// thamso is a new object of class A
	// When this function terminates, thamso will be destroyed.
	// thamso will call destructor.
}

int main()
{
	A a;
	//F(a);
	a.Print();

	_getch();
	return 0;
}