#ifndef class_docgia
#define class_docgia
#include"qly_phieumuon.h"
class docgia
{
protected:
	static unsigned int Dem;
public:
	unsigned int _ma;
	string ten;
	int tuoi;
	eLoaiDocGia loai;
	etinhtrang tinhtrang;
	docgia();
	~docgia();
	void nhap();
	void xuat();
};
#endif