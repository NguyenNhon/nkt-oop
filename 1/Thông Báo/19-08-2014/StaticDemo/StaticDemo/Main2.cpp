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

	A(const A &a)
	{
		s=new char[strlen(a.s)+1];
		strcpy(s, a.s);
	}

	void Print()
	{
		cout<<s<<endl;
	}
};

int main()
{
	A a;	
	{
		A b = a;// b is new object of class A.
	} // b will be destroyed here

	a.Print();

	_getch();
	return 0;
}