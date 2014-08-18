#include<iostream>

using namespace std;

class abstract A // lop ao
{
public:
	virtual void F1() = 0;
	virtual void F2() = 0;
};

class B: public A
{
public:
	void F1(){/* do something*/}
	void F2(){/* do something2*/}	
};

int main()
{
	_getch();
	return 0;
}