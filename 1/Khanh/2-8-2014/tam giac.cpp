#include <iostream>
#include <math.h>
using namespace std;
class tam_giac
{
public: 
	float a;
	float b;
	float c;
	
	float chu_vi()
	{ 
		return (float)a+b+c;
	}
	float dien_tich()
	{	
		float p=(a+b+c)/2;
		return (float)(sqrt(p*(p-a)*(p-b)*(p-c)));
	}

	void nhap_tam_giac()
	{
		cout<<"nhap so dai 3 canh"<<endl;
		cin>>a;
		cin>>b;
		cin>>c;
	}
	void xuat_tam_giac()
	{
		cout<<"chuvi:"<<endl;
		cout<<chu_vi()<<endl;
		cout<<"dien tich:"<<endl;
		cout<<dien_tich()<<endl;
	}
};
int main()
{
	tam_giac tamgiac;
	tamgiac.nhap_tam_giac();
	tamgiac.chu_vi();
	tamgiac.dien_tich();
	tamgiac.xuat_tam_giac();
	return 0;
	
}