#include<conio.h>
#include<iostream>
#include<string>

#define MAX_BOOK 100
#define MAX_READER 100
#define MAX_BORROW_BOOK 5
#define MAX_PHIEU_MUON 100

using namespace std;

enum LoaiSach
{
	SachGiaoKhoa = 1,
	SachGiaiTri = 2
};
enum LinhVuc
{
	MyThuat = 1,
	AmNhac = 2,
	Truyen = 3
};
enum LoaiDocGia
{
	ThieuNhi = 1, 
	ThieuNien = 2,
	TrungNien = 3
};
enum Lop
{
	MauGiao = 0, 
	Lop1 = 1, 
	Lop2 = 2, 
	Lop3 = 3, 
	Lop4 = 4, 
	Lop5 = 5, 
	Lop6 = 6, 
	Lop7 = 7, 
	Lop8 = 8, 
	Lop9 = 9, 
	Lop10 = 10, 
	Lop11 = 11, 
	Lop12 = 12
};
class Sach
{
protected:
	unsigned int gia_tien;
	string tac_gia;
	LoaiSach _loai;
public:
	unsigned int _ma;
	static unsigned int _dem;
	virtual int Get_loai(){return _loai;}
	virtual void nhap()
	{
	}
	virtual void xuat()
	{
	}
};
unsigned int Sach::_dem=0;
class Sach_Giaokhoa : public Sach
{
private:
	int lop;
public:
	Sach_Giaokhoa()
	{
		_loai=LoaiSach::SachGiaoKhoa;
	}
	~Sach_Giaokhoa()
	{
	}
	void nhap()
	{
		
		cout<<"nhap gia tien : ";
		cin>>gia_tien;
		fflush(stdin);
		cout<<"nhap ten tac gia :";
		getline(cin,tac_gia);
		do
		{
			cout<<"nhap tu 0 den 12 tuong uong voi lop mau giao den lop 12"<<endl;
			cout<<"SGK thuoc lop : ";
			cin>>lop;
		}while(lop<0 && lop>12);
		(Lop)lop;
		_dem++;
		_ma=_dem;
	}
	void xuat()
	{
		cout<<"\tMa Sach : "<<_ma<<"\tLoai : "<<_loai<<"\tgia tien : "<<gia_tien<<"\ttac gia : "<<tac_gia<<"\tlop : "<<lop<<endl;
	}
};
class Sach_Giaitri : public Sach
{
private:
	int lv;
public:
	Sach_Giaitri()
	{
		_loai=LoaiSach::SachGiaiTri;
	}
	~Sach_Giaitri()
	{
	}
	void nhap()
	{
		cout<<"nhap gia tien : ";
		cin>>gia_tien;
		fflush(stdin);
		cout<<"nhap ten tac gia :";
		getline(cin,tac_gia);
		do
		{
			cout<<"Nhap linh vuc cua sach"<<endl;
			cout<<"1.My thuat\n2.Am nhac\n3.Truyen"<<endl;
			cin>>lv;
		}while(lv<1 && lv>3);
		(LinhVuc)lv;
		_dem++;
		_ma=_dem;
	}
	void xuat()
	{
		cout<<"\tMa sach : "<<_ma<<"\tLoai : "<<_loai<<"\tgia tien : "<<gia_tien<<"\ttac gia : "<<tac_gia<<"\tlinh vuc : "<<lv<<endl;
	}
};
class Quanly_sach
{
private:
	int so_luong;
	Sach* _mang[MAX_BOOK];
public:
	Quanly_sach()
	{
		so_luong=0;
		for(int i=0;i<MAX_BOOK;i++)
			_mang[i]=NULL;
	}
	~Quanly_sach()
	{
		for(int i=0;i<MAX_BOOK;i++)
			if(_mang[i] != NULL)
			{
				delete _mang[i];
				_mang[i]=NULL;
			}
		delete[] _mang;
	}
	void them(Sach *sach)
	{
		if(so_luong<MAX_BOOK)
			_mang[so_luong]=sach;
		so_luong++;
	}
};
class Doc_gia
{
private:
	string ho_ten;
	unsigned int tuoi;
	LoaiDocGia _loai_docgia;
public:
	unsigned int _ma;
	static unsigned int _dem;
	Doc_gia(){}
	~Doc_gia(){}
	void nhap()
	{
		cout<<"\tNhap ho va ten doc gia : ";
		getline(cin,ho_ten);
		cout<<"nhap tuoi :";
		cin>>tuoi;
		++_dem;
		_ma=_dem;
	}
	int Get_loai()
	{
		if(6<=tuoi && tuoi<=18)
			return LoaiDocGia::ThieuNhi;
		else if(19<tuoi && tuoi<=35)
			return LoaiDocGia::ThieuNien;
		else if(36<tuoi && tuoi<=50)
			return LoaiDocGia::TrungNien;
	}
};
unsigned int Doc_gia::_dem=0;

int main()
{
	Quanly_sach *Qly=new Quanly_sach;
	Sach *Nhap;
	Nhap=new Sach_Giaokhoa;
	Nhap->nhap();
	Nhap->xuat();
	Nhap=new Sach_Giaitri;
	Nhap->nhap();
	Nhap->xuat();
	return 0;
}