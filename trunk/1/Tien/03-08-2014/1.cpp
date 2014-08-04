#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

class TamGiac
{
private:
	int A, B, C;
public:
	TamGiac();
	TamGiac(int a, int b, int c)
	{
		SetTamGiac(a, b, c);
	}
	~TamGiac()
	{
		cout << "Ham nay duoc goi truoc khi doi tuong bi huy!" << endl;
	}
	int GetA()
	{
		return this->A;
	}
	int  GetB()
	{
		return this->B;
	}
	int  GetC()
	{
		return this->C;
	}

	void SetTamGiac(int a, int b, int c)
	{
		if (a>(b + c) || b>(a + c) || c>(a + b))
		{
			cout << "3 canh tren k the tao thanh 1 tam giac!\n";
		}
		else
		{
			A = a;
			B = b;
			C = c;
		}
	}
	int ChuVi()
	{
		return this->A + this->B + this->C;
	}

	float DienTich()
	{
		float p= ChuVi()/float (2);
		 float s=sqrt(p*(p - GetA())*(p - GetB())*(p -GetC()));
		 return s;
	}
	void InTamGiac()
	{
		cout<< " a=" <<GetA() << " b=" << GetB() << " c=" << GetC() << "\n";
	}

};
void main()
{
	TamGiac tg1(2,3,4);
	
	tg1.InTamGiac();
	cout<<"chu vi :"<<tg1.ChuVi()<<endl;
	cout<<"dien tich:"<<tg1.DienTich()<<endl;
}