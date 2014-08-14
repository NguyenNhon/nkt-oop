#include <iostream>
#include <string>
#include "BienToanCuc.h"

using namespace std;

class Sach
{
protected:
	string tacgia;
	eLoaiSach ls;
	unsigned int giatien,masach,tinhtrang;	
public:
	Sach()
	{
		tinhtrang=0;
	}
	~Sach();
	virtual void NhapLV();
	virtual void NhapLop();
	 void Nhap()
	{
		cout<<"ten tac gia: "<<endl;
		cin>>tacgia;
		cout<<"gia tien: "<<endl;
		cin>>giatien;
		
	}
	 void Xuat()
	{
		cout<<"ten tac gia: "<<tacgia<<endl;
		cout<<"gia tien: "<<giatien<<endl;
	}
	 virtual void XuatLV();
	 virtual void XuatLop();
	 eLoaiSach GetLoaiSach()
	 {
		return ls;
	 }
};
class SGK:public::Sach
{
private:
	eLop lop;
public:
	void NhapLop()
	{
		cout<<" lop : "<<endl;
		int c;
		cin>>c;
		lop=(eLop)c;
	}
	void XuatLop()
	{
		cout<<" lop : "<<lop<<endl;
	}

};
class SGT:public::Sach
{
private:
	eLinhVuc lv;
public:
	void NhapLV()
	{
		cout<<" linh vuc : "<<endl;
		int c;
		cin>>c;
		lv=(eLinhVuc)c;
	}
};

class QLSach:public::Sach
{
private:
	static unsigned int stt;
	
	Sach a[MAX_BOOK];
public:
	void ThemSach()
	{
		Sach *s;
	cout<<" loai sach gi?\n 1/Sach Giao khoa\n 2/Giai Tri"<<endl;
		unsigned int c;
		cin>>c;
		if(c==eLoaiSach::eSachGiaiTri)
		{
			s=new SGT;
			s->NhapLV();
		}
		else
		{
			s=new SGK;
			s->NhapLop();
		}
		s->Nhap();
		masach=stt;
		a[++stt]=*s;
	}
	void XuatDS()
	{
		for (int i=1;i<stt;i++)
		{
			a[i].Xuat();
			if(a[i].GetLoaiSach()==eSachGiaoKhoa)
				a[i].XuatLop();
			else a[i].XuatLV();
		}
	}
};
class DocGia
{
protected:
	string ten;
	unsigned int tuoi,madg;
	eLoaiDocGia loai;
	static unsigned int demdg;
public:
	DocGia();
	~DocGia();
	void Nhap()
	{
		cout<<" Ten doc gia: "<<endl;
		cin>>ten;
		cout<<" tuoi: "<<endl;
		cin>>tuoi;
		int c;
		if(tuoi<19)
			c=1;
		else if(tuoi<36)
			c=2;
		else c=3;
		loai=(eLoaiDocGia)c;
	}
	void Xuat()
	{
		cout<<" Ten doc gia: "<<ten<<endl;
		cout<<" tuoi: "<<tuoi<<endl;
	}
};
unsigned int DocGia::demdg=0;
class QLDG:public::DocGia
{
private :
	DocGia *b[MAX_READER];
public:
	void ThemDG()
	{
		DocGia *a=new DocGia;
		a->madg= ++demdg;
		
	}
};

void main()
{
	
}