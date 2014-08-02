#include <iostream>
#include <math.h>

using namespace std;

class TamGiac
{
public:
	int a,b,c;
	void Nhap()
	{
		cout<<"nhap do dai cac canh: ";
		cin>>a>>b>>c;
	}
	void Xuat()
	{
		cout<<"chieu dai cac canh: "<<a<<b<<c;

	}
	int ChuVi()
	{
		return a+b+c;
	}

	float DienTich()
	{
		float p=ChuVi()/2;
		return sqrt(float (p*(p -a)*(p - b)*(p-c)));
	}
};

void main()
{
	TamGiac tg;
	tg.Nhap();
	cout<<"Chu Vi:"<<tg.ChuVi()<<endl;
	cout<<"Dien Tich: "<<tg.DienTich()<<endl;
}