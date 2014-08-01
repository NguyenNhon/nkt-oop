#include<iostream>

using namespace std;

struct Phan_So_Struct
{
	int _tu_so;
	int _mau_so;
};

float Gia_Tri_Phan_So(Phan_So_Struct phan_so)
{
	return (float)phan_so._tu_so/phan_so._mau_so;
}
void xuat(Phan_So_Struct phan_so)
{
	cout<<"Tu so: "<<phan_so._tu_so<<endl;
	cout<<"Mau so: "<<phan_so._mau_so<<endl;
}

int main()
{
	Phan_So_Struct phan_so;
	phan_so._tu_so=5;
	phan_so._mau_so=6;

	cout<<"Tu so: "<<phan_so._tu_so<<endl;
	cout<<"Mau so: "<<phan_so._mau_so<<endl;

	cout<<"Gia tri phan so: "<<Gia_Tri_Phan_So(phan_so)<<endl;

	return 0; // Indicate that program terminates successfully
}