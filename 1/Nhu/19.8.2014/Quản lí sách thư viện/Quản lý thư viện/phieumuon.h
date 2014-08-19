#ifndef phieu_muon
#define phieu_muon

#include<string>
#include<iostream>
#include"bien_toan_cuc.h"
#include"quanlysach.h"

using namespace std;

class Phieu_muon
{
private:
	unsigned int _ma;
	static int _dem;
	string ngay;
	unsigned int ma_sach;
	int so_luong; 
	int _mang[MAX_BORROW_BOOK];
public:
	Phieu_muon();
	~Phieu_muon();
	unsigned int ma_docgia;
	void nhap();
	void xuat();
	void Sach_da_muon();
};

#endif
