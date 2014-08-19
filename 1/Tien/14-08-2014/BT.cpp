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
	QLSach()
	{
		stt=0;
	}
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
		masach=++stt;
		a[stt]=*s;
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
private:
	string ten;
	unsigned int tuoi,madg;
	eLoaiDocGia loai;
	
public:
	DocGia();
	DocGia(string n,unsigned int t,unsigned d)
	{
		tuoi=t;
		ten=n;
		int c;
		if(tuoi<19)
			c=1;
		else if(tuoi<36)
			c=2;
		else c=3;
		loai=(eLoaiDocGia)c;
		madg=d;
	}
	~DocGia();
	string Ten()
	{
		return ten;
	}
	unsigned int Tuoi()
	{
		return tuoi;
	}
	unsigned MaDG()
	{
		return madg;
	}
	eLoaiDocGia LoaiDG()
	{
		return loai;
	}
	
};

class QLDG:public::DocGia
{
protected :
	DocGia *b[MAX_READER];
	 unsigned int demdg;
	 QLDG()
	 {
		demdg=0;
		for(int i=0;i<MAX_READER;i++)
		b[i]=NULL;
	 }
	 
public:
	static QLDG *qldg;
	~QLDG()
	{
		for(int i=0;i<demdg;i++)
			b[i]=NULL;
		
	}
	void ThemDG()
	{
		string n;
		unsigned int t;
		cout<<" Ten doc gia: "<<endl;
		cin>>n;
		do{
		cout<<" tuoi: "<<endl;
		cin>>t;
		}while(t<16&&t>50);
		
		if(demdg<MAX_READER-1)
			b[demdg]=new DocGia(n,t,demdg++);
		
	}
	void XuatDSDG()
	{
		if(demdg==0)
			cout<<"khong co doc gia\n";
		else
			for(int i=0;i<demdg;i++)
			{
				cout<<i<<"/\n";
				cout<<"		Ma Doc Gia"<<b[i]->MaDG();
				cout<<"		Ten doc gia: "<<b[i]->Ten();
				cout<<"		Tuoi: "<<b[i]->Tuoi()<<endl;
				
			}
	}

	DocGia *TimDocGia(unsigned int x)
	{
		if(x<0||x>demdg)
			return NULL;
		return b[x];
	}
};
QLDG *QLDG::qldg=new QLDG();

struct Time
{
	unsigned int dd,mm,yy;
};
struct SachMuon
{
	unsigned int a[MAX_BORROW_BOOK];
};

class PhieuMuon:public::QLDG
{
private:
	unsigned int MDG,maphieu;
	Time time;
	SachMuon SM;
public:
	PhieuMuon();
	PhieuMuon(unsigned int madg,Time t,unsigned mp,SachMuon sm)
	{
		MDG=madg;
		time=t;
		maphieu=mp;
		SM=sm;
	}
	~PhieuMuon();
	
};
class QLPM:public::PhieuMuon
{
protected:
	unsigned int dempm;
	PhieuMuon *pm[MAX_PHIEU_MUON];
	QLPM ()
	{
		dempm=0;
		for(int i=0;i<MAX_PHIEU_MUON;i++)
			pm[i]=NULL;
	}
public:
	static QLPM*qlpm;
	~QLPM()
	{
		for(int i=0;i<dempm;i++)
			pm[i]=NULL;
	}
	void ThemPM()
	{
		Time t;
		unsigned int madg;
		SachMuon sm;
		cout<<"Nhap Ngay muon sach (ngay thang nam cach nhau boi dau " "): ";
		cin>>t.dd>>t.mm>>t.yy;
		cout<<"Ma doc gia: ";
		cin>>madg;
		cout<<"nhap lan luot tung ma sach (toi da 5 ma sach): ";
		for(int i=0;i<MAX_BORROW_BOOK;i++)
			cin>>sm.a[i];	
		pm[demdg]=new PhieuMuon(madg,t,dempm,sm);
	}

	void XuatDSM()
	{
		for(int j=0;j<dempm;j++)
		{
			pm[j]->
			cout<<"		Ma Doc Gia"<<b[i]->MaDG();
				cout<<"		Ten doc gia: "<<b[i]->Ten();
				cout<<"		Tuoi: "<<b[i]->Tuoi()<<endl;
		}
	}
};

void main()
{
		
}