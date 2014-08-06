#include<iostream>

using namespace std;

class PhanSo_Class
{
private:
	int _tu_so;
	int _mau_so;
public:

	// Constructor
	PhanSo_Class(int tu, int mau)
	{
		Set_Tu_So(tu);
		Set_Mau_So(mau);
	}

	// Destructor
	~PhanSo_Class()
	{
		cout<<"Ham nay duoc goi truoc khi doi tuong bi huy!"<<endl;
	}

	int Get_Tu_So()
	{
		return _tu_so;
	}

	int Get_Mau_So()
	{
		return _mau_so;
	}

	void Set_Tu_So(int tu)
	{
		_tu_so=tu;
	}


		}
	}

	void In_Phan_So()
	{
		cout<<_tu_so<<"/"<<_mau_so<<endl;
	}
};

int main()
{	
	PhanSo_Class phan_so(3,2); // Call constructor here
	
	phan_so.In_Phan_So();
	cout<<"Tu so: "<<phan_so.Get_Tu_So()<<endl;

	return 0;
}
// Call destructor here