#include <iostream>
#include <string>
#include <conio.h>
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
	unsigned int TinhTrang()
	{
		return tinhtrang;
	}
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
	unsigned int stt;
	
	Sach *a[MAX_BOOK];

	QLSach()
	{
		stt=0;
		for (int i=0;i<MAX_BOOK;i++)
			a[i]=NULL;
	}

public:
	static QLSach *qls;
	~QLSach()
	{
		for(int i=0;i<stt;i++)
			a[stt];
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
		a[stt]=s;
	}
	void XuatDS()
	{
		for (int i=1;i<stt;i++)
		{
			a[i]->Xuat();
			if(a[i]->GetLoaiSach()==eSachGiaoKhoa)
				a[i]->XuatLop();
			else a[i]->XuatLV();
		}
	}
	void XuatDSM()
	{
		for (int i=1;i<stt;i++)
		{
			if(a[i]->TinhTrang()==1)
			{
			a[i]->Xuat();
			if(a[i]->GetLoaiSach()==eSachGiaoKhoa)
				a[i]->XuatLop();
			else a[i]->XuatLV();
			}
		}
	}
	void XuatDSCM()
	{
		for (int i=1;i<stt;i++)
		{
			if(a[i]->TinhTrang()==0)
			{
			a[i]->Xuat();
			if(a[i]->GetLoaiSach()==eSachGiaoKhoa)
				a[i]->XuatLop();
			else a[i]->XuatLV();
			}
		}
	}
};
QLSach *QLSach ::qls=new QLSach();
class DocGia
{
protected:
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
	unsigned int madocgia()
	{
		return MDG;
	}
	
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
			int i=pm[j]->madocgia();
			cout<<"		Ma Doc Gia"<<b[i]->MaDG();
				cout<<"		Ten doc gia: "<<b[i]->Ten();
				cout<<"		Tuoi: "<<b[i]->Tuoi()<<endl;
		}
	}
};
QLPM* QLPM::qlpm=new QLPM();
class QuanLyThuVien
{
	public:
        QuanLyThuVien()
		{}
 
        
 
        void ThemSach()
        {
                QLSach::qls->ThemSach();
        }
        void ThemDocGia()
        {
                QLDG::qldg->ThemDG();
        }
        void MuonSach()
        {
                QLPM::qlpm->ThemPM();
        }
        void InDanhSachSach()
        {
                QLSach::qls->XuatDS();
        }
        void InDanhSachDocGia()
        {
                QLDG::qldg->XuatDSDG();
        }
        void InDanhSachSachCon()
        {
                QLSach::qls->XuatDSM();
        }
        void InDanhSachSachDaMuon()
        {
                QLSach::qls->XuatDSCM();
        }
        void InDanhSachDocGiaMuonSach()
        {
                QLPM::qlpm->XuatDSM();
        }
		void TraCuuDocGia()
		{
			
		}
};
int main()
{
	QuanLyThuVien quanLy;
        while (1)
        {
                system("cls");         
                int tuyChon;
 
                cout<<"1. Nhap sach moi!"<<endl;
                cout<<"2. Nhap doc gia moi!"<<endl;
                cout<<"3. Muon sach"<<endl;
                cout<<"4. In danh sach sach!"<<endl;
                cout<<"5. In danh sach doc gia!"<<endl;
                cout<<"6. Danh sach sach con!"<<endl;
                cout<<"7. Danh sach sach da cho muon!"<<endl;
                cout<<"8. Danh sach doc gia da muon!"<<endl;
                cout<<"9. Tra cuu doc gia!"<<endl;
                cout<<"10.Tra cuu sach!"<<endl;
                cout<<"11.Thoat chuong trinh!"<<endl;
               
                cin>>tuyChon;
                cin.ignore();
 
                switch (tuyChon)
                {
                case 1:
                        quanLy.ThemSach();
                        break;
                case 2:
                        quanLy.ThemDocGia();
                        break;
                case 3:
                        quanLy.MuonSach();
                        break;
                case 4:
                        quanLy.InDanhSachSach();
                        break;
                case 5:
                        quanLy.InDanhSachDocGia();
                        break;
                case 6:
                        quanLy.InDanhSachSachCon();
                        break;
                case 7:
                        quanLy.InDanhSachSachDaMuon();
                        break;
                case 8:
                        quanLy.InDanhSachDocGiaMuonSach();
                        break;
                /*case 9:
                        quanLy.TraCuuDocGia();
                        break;
                case 10:
                        quanLy.TraCuuSach();
                        break;*/
                case 11:
                        cout<<"Nhan phim bat ki de thoat chuong trinh...."<<endl;
                        _getch();
                       return 0;
                }
 
                cout<<"Nhan phim bat ki de tiep tuc...."<<endl;
                _getch();
        }	
		return 0;
}