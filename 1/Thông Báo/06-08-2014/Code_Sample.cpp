#include<iostream>

using namespace std;

enum LoaiHinhHoc
{
	eHinhVuong,
	eHinhTamGiac
};

class HinhHoc
{
protected:
	LoaiHinhHoc _loai;
public:
	virtual void Nhap(){}
	virtual void Xuat()
	{
		cout<<"Day la hinh hoc!"<<endl;
	}
	virtual int ChuVi(){return 0;}
	virtual int DienTich(){return 0;}
	LoaiHinhHoc GetLoai(){return _loai;}
};

class HinhTamGiac: public HinhHoc
{
public:
	HinhTamGiac()
	{
		_loai=LoaiHinhHoc::eHinhTamGiac;
	}
	int ChuVi()
	{
		return 5;
	}
	void Xuat()
	{
		cout<<"Day la hinh tam giac!"<<endl;
	}
};

class HinhVuong:public HinhHoc
{
public:
	HinhVuong()
	{
		_loai=LoaiHinhHoc::eHinhVuong;
	}
};

int main()
{
	HinhHoc *object1=new HinhHoc();
	HinhHoc *object2=new HinhTamGiac();
	HinhHoc *object3=new HinhVuong();

	object1->Xuat();
	object2->Xuat();
	object3->Xuat();

	delete object1;
	delete object2;
	delete object3;

	return 0;
}