#ifndef SACH_GIAI_TRI_H
#define SACH_GIAI_TRI_H

#include "Sach.h"

class SachGiaiTri: public Sach
{
private:
	eLinhVuc _linhVuc;
public:
	SachGiaiTri(int gia, string tensach, eLinhVuc linhVuc):Sach(gia, tensach)
	{
		_linhVuc=linhVuc;
		_loaiSach=eLoaiSach::eSachGiaoKhoa;
	}

	eLinhVuc LinhVuc(){return _linhVuc;}

	void Xuat()
	{
		Sach::Xuat();
		cout<<"Linh vuc: "<<_linhVuc;
	}
};

#endif	