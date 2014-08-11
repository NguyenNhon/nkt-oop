#include<iostream>
#include<conio.h>
using namespace std;

class So_Phuc
{
	int _thuc;
	int _ao;
public:
	So_Phuc()
	{

	}
	So_Phuc(int thuc, int ao)
	{
		_thuc=thuc;
		_ao=ao;
	}

	// copy constructor khoi tao sao chep
	So_Phuc(const So_Phuc &a)
	{
		_thuc=a._thuc;
		_ao=a._ao;
	}

	// Assignment operator toan tu gan bang
	So_Phuc& operator = (const So_Phuc &a)
	{
		_thuc=a._thuc;
		_ao=a._ao;
		return *this;
	}

	// Plus operator toan tu cong
	So_Phuc operator + (const So_Phuc &b)
	{
		So_Phuc temp(_thuc+b._thuc, _ao+b._ao);
		return temp;
	}

	So_Phuc operator - (const So_Phuc &b)
	{
		So_Phuc temp(_thuc-b._thuc, _ao-b._ao);
		return temp;
	}

	friend ostream& operator << (ostream &out, So_Phuc &so_phuc)
	{
		out<<"Thuc: "<<so_phuc._thuc<<" Ao: "<<so_phuc._ao<<endl;
		return out;
	}	

	friend istream& operator >> (istream &in, So_Phuc &so_phuc)
	{
		cout<<"Nhap phan thuc, ao: ";
		in>>so_phuc._thuc>>so_phuc._ao;
		return in;
	}
};

int main()
{
	So_Phuc so_phuc1, so_phuc2, so_phuc3, so_phuc4;

	cin>>so_phuc1;
	cin>>so_phuc2;

	so_phuc3=so_phuc1+so_phuc2;
	so_phuc4=so_phuc1-so_phuc2;

	cout<<so_phuc1<<endl;
	cout<<so_phuc2<<endl;
	cout<<so_phuc3<<endl;
	cout<<so_phuc4<<endl;

	_getch();
	return 0;
}