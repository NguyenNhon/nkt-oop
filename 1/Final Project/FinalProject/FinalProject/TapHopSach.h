#ifndef TAP_HOP_SACH_H
#define TAP_HOP_SACH_H

#include "SachGiaoKhoa.h"
#include "SachGiaiTri.h"

class TapHopSach
{
protected:
	Sach* _sach[MAX_BOOK];
	unsigned int _viTri;

	TapHopSach()
	{
		_viTri=0;
		for (int i=0; i<MAX_BOOK; ++i)
		{
			_sach[i]=NULL;
		}
	}

public:
	static TapHopSach* tapHopSach;

	~TapHopSach()
	{
		for (int i = 0; i <_viTri ; i++)
		{
			delete _sach[i];
			_sach[i]=NULL;
		}
	}

	void ThemSach()
	{
		unsigned int gia;
		string tensach;

		int luachon;
		do
		{
			cout<<"1. Nhap sach giai tri\n2. Nhap sach giao khoa\n";
			cin>>luachon;
		}
		while(luachon!=1 && luachon!=2);

		cout<<"Nhap gia sach: ";
		cin>>gia;
		cin.ignore();
		cout<<"Nhap ten sach: ";
		cin>>tensach;		
		
		if(luachon==eLoaiSach::eSachGiaiTri)
		{
			int linhVuc;
			do
			{
				cout<<"1. My thuat\n2. Am nhac\n3. Truyen: ";
				cin>>linhVuc;
			}while (linhVuc<1 || linhVuc>3);
			_sach[_viTri] = new SachGiaiTri(gia, tensach, (eLinhVuc)linhVuc);
			_viTri++;
		}else 
		{
			int lop;
			do
			{
				cout<<"Nhap so tu 0 toi 12 the hien lop: ";
				cin>>lop;
			}while (lop<0 || lop>12);
			_sach[_viTri] = new SachGiaoKhoa(gia, tensach, (eLop)lop);
			_viTri++;
		}
		
	}

	int SoLuongSach(){return _viTri;}

	Sach* TimSach(int maSach)
	{
		for (int i = 0; i < _viTri; i++)
		{
			if(_sach[i]->MaSach()==maSach)
				return _sach[i];
		}
		return NULL;
	}

	void InDanhSach()
	{
		if(_viTri==0)
		{
			cout<<"Khong co sach!"<<endl;
		}
		else
		{
			for (int i = 0; i < _viTri; i++)
			{
				cout<<"Ma: "<<_sach[i]->MaSach()<<" Ten: "<<_sach[i]->TenSach()<<" Gia: "<<_sach[i]->GiaTien()<<endl;
			}
			cout<<endl;
		}
	}

	void InSachChuaMuon()
	{
		if(_viTri==0)
		{
			cout<<"Khong co sach!"<<endl;
		}
		else
		{
			for (int i = 0; i < _viTri; i++)
			{
				if(_sach[i]->TinhTrang()==eTinhTrang::eCon)
					cout<<"Ma: "<<_sach[i]->MaSach()<<" Ten: "<<_sach[i]->TenSach()<<" Gia: "<<_sach[i]->GiaTien()<<endl;
			}
			cout<<endl;
		}
	}

	void InDanhSachDaMuon()
	{
		if(_viTri==0)
		{
			cout<<"Khong co sach!"<<endl;
		}
		else
		{
			for (int i = 0; i < _viTri; i++)
			{
				if(_sach[i]->TinhTrang()==eTinhTrang::eHet)
					cout<<"Ma: "<<_sach[i]->MaSach()<<" Ten: "<<_sach[i]->TenSach()<<" Gia: "<<_sach[i]->GiaTien()<<endl;
			}
			cout<<endl;
		}
	}
};

TapHopSach* TapHopSach::tapHopSach =new TapHopSach();
#endif