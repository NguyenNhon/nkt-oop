#ifndef class_sach
#define class_sach

#include<iostream>
#include<string>
#include<conio.h>
#include"bien_toan_cuc.h"

using namespace std;

class Sach
{
protected:
	unsigned int gia_tien;
	string tac_gia;
	LoaiSach _loai;
public:
	unsigned int _ma;
	static unsigned int _dem;
	int tinh_trang;
	Sach();
	virtual void nhap();
	virtual void xuat();
};

#endif