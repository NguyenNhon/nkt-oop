#ifndef class_phieumuon
#define class_phieumuon
#include<iostream>
#include<string>
#include"qlysach.h"
using namespace std;
class phieumuon: public Qly_sach
{
public:
	static unsigned int dem;
	unsigned int _ma;
	string ngay;
	int ma_sach;
	int ma_dg;
	int sl_sach;
	int a[5];
	void nhap();
	void xuat();
};
#endif