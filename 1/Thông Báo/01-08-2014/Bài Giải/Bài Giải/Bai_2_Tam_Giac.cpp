#include<iostream>

using namespace std;

class Tam_Giac
{
public:
	float _a;
	float _b;
	float _c;

	void Nhap()
	{
		cout<<"Nhap do dai 3 canh a, b, c: "<<endl;
		cin>>_a>>_b>>_c;
	}

	void Xuat()
	{
		cout<<"A: "<<_a<<" B: "<<_b<<" C: "<<_c<<endl;
	}

	float Tinh_Chu_Vi()
	{
		return _a*_b*_c;
	}

	// Tinh theo cong thuc Heron
	// http://vi.wikipedia.org/wiki/C%C3%B4ng_th%E1%BB%A9c_Heron
	float Tinh_Dien_Tich()
	{
		float nua_chu_vi = this->Tinh_Chu_Vi()/2;
		return sqrt(nua_chu_vi*(nua_chu_vi-_a)*(nua_chu_vi-_b)*(nua_chu_vi)-_c);
	}
};

int main()
{	
	Tam_Giac tam_giac;
	tam_giac.Nhap();
	tam_giac.Xuat();
	cout<<"Chu vi: "<<tam_giac.Tinh_Chu_Vi()<<endl;
	cout<<"Dien tich: "<<tam_giac.Tinh_Dien_Tich()<<endl;

	return 0;
}