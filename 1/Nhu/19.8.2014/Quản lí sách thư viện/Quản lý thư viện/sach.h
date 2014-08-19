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
	LoaiSach _loai;
	TinhTrangSach _tinhTrang;
	static unsigned int _dem;
public:
	Sach();
	~Sach();
	unsigned int gia_tien;
	string tac_gia;
	unsigned int _ma;

	bool Tinh_trang();
	
	void ChoMuon();

	virtual void nhap();
	
	virtual void xuat();
};

#endif