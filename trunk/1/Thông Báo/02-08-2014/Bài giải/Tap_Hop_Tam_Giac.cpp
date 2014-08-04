#include<iostream>
#include <conio.h>

using namespace std;

enum Canh_Tam_Giac
{
	Canh_A,
	Canh_B,
	Canh_C
};

class Tam_Giac
{
private:
	unsigned int _a;
	unsigned int _b;
	unsigned int _c;

	// Tai sao ham nay lai de la private?
	bool kiem_tra_dieu_kien_tam_giac(unsigned int a, unsigned int b, unsigned int c)
	{		
		if(a+b<c || a+c<b||b+c<a)
			return false;
		return true;
	}

public:
	Tam_Giac()
	{
		// Set all value to 0 indicates that these value have not set by user
		_a=0;
		_b=0;
		_c=0;
	}

	Tam_Giac(unsigned int a, unsigned int b, unsigned int c)
	{
		if(Set(a,b,c)==false)
		{
			cout<<"Thao tac khong hop le! nhan phim bat ki de thoat!"<<endl;
			getch();
			exit(1);
		}
	}

	bool Set(unsigned int a, unsigned int b, unsigned int c)
	{
		if( a>0 && b>0 && c>0 && kiem_tra_dieu_kien_tam_giac(a,b,c)==true)
		{
			this->_a=a;
			this->_b=b;
			this->_c=c;
			return true;
		}
		else
		{
			return false;
		}
	}

	int Tinh_Chu_Vi()
	{
		if(_a == 0 || _b == 0 || _c == 0)
		{
			cout<<"Chua gan gia tri cho du lieu!"<<endl<<"Nhan phim bat ki de thoat!";
			getch();
			exit(1);
		}
		return _a + _b + _c;
	}

	float Tinh_Dien_Tich()
	{
		float nua_chu_vi = this->Tinh_Chu_Vi()/2.0;
		return sqrt(nua_chu_vi*(nua_chu_vi-_a)*(nua_chu_vi-_b)*(nua_chu_vi-_c));
	}

	int Get_Canh(Canh_Tam_Giac canh)
	{
		if(canh == Canh_A)
			return _a;
		if(canh == Canh_B)
			return _b;
		if(canh == Canh_C)
			return _c;
	}

	bool Set(Canh_Tam_Giac canh, unsigned int gia_tri)
	{
		if(gia_tri==0)
			return false;

		switch (canh)
		{
		case Canh_A:
			if(kiem_tra_dieu_kien_tam_giac(gia_tri, _b, _c)==false)
				return false;
			this->_a=_a;
			break;
		case Canh_B:
			if(kiem_tra_dieu_kien_tam_giac(_b, gia_tri, _c)==false)
				return false;
			this->_b=gia_tri;
			break;
		case Canh_C:
			if(kiem_tra_dieu_kien_tam_giac(_a, _b, gia_tri)==false)
				return false;
			this->_c=gia_tri;
			break;
		}
	}

	void Xuat()
	{
		cout<<"A: "<<_a<<"B: "<<_b<<" C: "<<_c<<endl;
	}
};

class Tap_Hop_Tam_Giac 
{
private:
	Tam_Giac _mang[20];	

	int _so_phan_tu;
public:	

	// Constructor
	Tap_Hop_Tam_Giac()
	{
		this->_so_phan_tu=0;	
	}

	// Destructor
	~Tap_Hop_Tam_Giac()
	{		
	}

	void Them(Tam_Giac tam_giac)
	{
		if(_so_phan_tu<20)
		{
			_mang[_so_phan_tu]=tam_giac;
			++_so_phan_tu;
		}
	}

	int Get_So_Luong_Tam_Giac()
	{
		return _so_phan_tu;
	}

	void Xuat()
	{
		cout<<"So luong phan tu: "<<_so_phan_tu<<endl;
		for (int i = 0; i < _so_phan_tu; i++)
		{			
			_mang[i].Xuat();
		}
	}

	int Tinh_Tong_Chu_Vi()
	{
		int tong=0;
		for (int i = 0; i < _so_phan_tu; i++)
		{			
			tong+=_mang[i].Tinh_Chu_Vi();
		}
		return tong;
	}

	int Tinh_Tong_Dien_Tich()
	{
		int tong=0;
		for (int i = 0; i < _so_phan_tu; i++)
		{			
			tong+=_mang[i].Tinh_Dien_Tich();
		}
		return tong;
	}
};

int main()
{		
	Tam_Giac tam_giac_1(4,5,6);
	Tam_Giac tam_giac_2(3,2,4);
	Tam_Giac tam_giac_3(3,5,4);

	Tap_Hop_Tam_Giac tap_hop;
	tap_hop.Them(tam_giac_1);
	tap_hop.Them(tam_giac_2);
	tap_hop.Them(tam_giac_3);

	cout<<"So luong tam giac trong tap hop: "<<tap_hop.Get_So_Luong_Tam_Giac()<<endl;
	cout<<"Danh sach tam giac trong tap hop: "<<endl;
	tap_hop.Xuat();
	cout<<"Tong chu vi: "<<tap_hop.Tinh_Tong_Chu_Vi()<<endl;
	cout<<"Tong dien tich:"<<tap_hop.Tinh_Tong_Dien_Tich()<<endl;
	return 0;
}
