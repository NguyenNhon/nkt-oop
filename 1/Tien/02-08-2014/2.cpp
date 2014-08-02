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
		return sqrt(float (ChuVi()*(ChuVi() -a)*(ChuVi() - b)*(ChuVi()-c)));
	}
};

void main()
{
	TamGiac tg;
	tg.Nhap();
	cout<<"Chu Vi:"<<tg.ChuVi()<<endl;
	cout<<"Dien Tich: "<<tg.DienTich()<<endl;
}