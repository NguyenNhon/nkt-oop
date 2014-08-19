#ifndef SACH_GIAO_KHOA_H
#define SACH_GIAO_KHOA_H

#include "Sach.h"

class SachGiaoKhoa: public Sach
{
private:
	eLop _lop;
public:
	SachGiaoKhoa(int gia, string tacgia, eLop lop):Sach(gia, tacgia)
	{
		_lop=lop;
		_loaiSach=eLoaiSach::eSachGiaoKhoa;
	}

	eLop Lop(){return _lop;}
	void Xuat()
	{
		Sach::Xuat();
		cout<<"Lop: "<<_lop;
	}
};
#endif
