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
};

int main()
{
	PhanSo_Class phan_so;
	phan_so._tu_so=5;
	phan_so._mau_so=6;
	
	cout<<"Tu so: "<<phan_so._tu_so<<endl;
	cout<<"Mau so: "<<phan_so._mau_so<<endl;

	cout<<"Gia tri phan so: "<<phan_so.Gia_Tri_Phan_So()<<endl;

	return 0; // Indicate that program terminates successfully
}