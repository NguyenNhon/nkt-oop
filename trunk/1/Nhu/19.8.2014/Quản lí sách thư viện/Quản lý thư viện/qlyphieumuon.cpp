#include"qlyphieumuon.h"


Qly_phieumuon::Qly_phieumuon()
{
	so_luong=0;
	for(int i=0;i<MAX_PHIEU_MUON;i++)
		_mang[i]=NULL;
}

Qly_phieumuon::~Qly_phieumuon()
{
	for(int i=0;i<MAX_PHIEU_MUON;i++)
		if(_mang[i] != NULL)
		{
			delete _mang[i];
			_mang[i]=NULL;
		}
	delete[] _mang;
}

void Qly_phieumuon::them(Phieu_muon *pmuon)
{
	if(so_luong<MAX_PHIEU_MUON)
		_mang[so_luong]=pmuon;
	so_luong++;
}

void Qly_phieumuon::xuat()
{
	for(int i=0;i<so_luong;i++)
		_mang[i]->xuat();
}

void Qly_phieumuon::KiemTra()
{
	for(int i=0;i<so_luong;i++)
		_mang[i]->Sach_da_muon();
}

Qly_phieumuon* Qly_phieumuon::qly_phieumuon=new Qly_phieumuon();
