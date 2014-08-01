#include<iostream>

using namespace std;
class PhanSo_Class
{
public:
	int _tu_so;

	int _mau_so;

	float Gia_Tri_Phan_So()
	{
		return (float)_tu_so/_mau_so;
	}

	void In_Phan_So()
	{
		cout<<"Tu so: "<<_tu_so<<endl;
		cout<<"Mau so: "<<_mau_so<<endl;
	}

	// Dung phep quy dong de cong phan so
	PhanSo_Class Cong_Phan_So(PhanSo_Class phan_so)
	{
		_tu_so = _tu_so*phan_so._mau_so + phan_so._tu_so;
		_mau_so=_mau_so*phan_so._mau_so;
		return *this;
	}
};

int main()
{
	PhanSo_Class phan_so_1;
	PhanSo_Class phan_so_2;

	phan_so_1._tu_so=5;
	phan_so_1._mau_so=6;
	phan_so_2._tu_so=7;
	phan_so_2._mau_so=8;

	phan_so_1.Cong_Phan_So(phan_so_2);
	phan_so_1.In_Phan_So();

	return 0; // Indicate that program terminates successfully
}