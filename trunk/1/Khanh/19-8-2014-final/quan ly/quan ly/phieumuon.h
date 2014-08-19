#ifndef class_phieumuon
#define class_phieumuon
#include"qlysach.h"
class phieumuon
{
protected:
	static unsigned int dem;
	string ngay;
public:
	unsigned int _ma;
	int ma_dg;
	int sl_sach;
	int a[5];
	void nhap();
	void xuat();
};
#endif