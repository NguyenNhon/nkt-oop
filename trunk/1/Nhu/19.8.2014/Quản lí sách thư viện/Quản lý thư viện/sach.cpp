#include"sach.h"
#include"qlyphieumuon.h"

unsigned int Sach::_dem=0;
Sach::Sach()
{
	_tinhTrang=TinhTrangSach::Con;
}
Sach::~Sach(){}

bool Sach::Tinh_trang()
{
	if(_tinhTrang==TinhTrangSach::Con)
		return false;
	return true;
}
void Sach::ChoMuon()
{
	_tinhTrang=TinhTrangSach::Het;
}
void Sach::nhap(){}
void Sach::xuat(){}