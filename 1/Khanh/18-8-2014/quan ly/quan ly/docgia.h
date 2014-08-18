#ifndef class_docgia
#define class_docgia
#include<iostream>
#include<string>
#include"qlysach.h"
using namespace std;
class docgia
{
private:
	string ten;
	int tuoi;
public:
	unsigned int _ma;
	static unsigned int Dem;
	eLoaiDocGia loai;
	void nhap();
	void xuat();
};
#endif