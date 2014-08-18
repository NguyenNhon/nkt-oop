#ifndef class_sach
#define class_sach
#include<iostream>
#include<string>
#include"bientoancuc.h"
using namespace std;

class sach
{
protected:
	unsigned int giatien;
	string tacgia;
	eLoaiSach loai;
public:
	eTinhTrang tinhtrang;
	unsigned int _ma;
	static unsigned int Dem;
	virtual void nhap();
	virtual void xuat();
};

#endif