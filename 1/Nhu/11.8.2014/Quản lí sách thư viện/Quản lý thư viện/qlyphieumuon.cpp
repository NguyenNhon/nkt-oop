#include"qlyphieumuon.h"
#include"quanlysach.h"


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

void Qly_phieumuon::Tinh_trang()
{
	for(int i=0;i<so_luong;i++)
		for(int j=0;j<Quanly_sach::;j++)
			if(_mang[i]->ma_sach == Quanly_sach::_mang[j]
}