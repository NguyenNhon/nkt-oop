#ifndef phieu_muon
#define phieu_muon

#include<string>
#include<iostream>
#include"bien_toan_cuc.h"
using namespace std;

class Phieu_muon
{
private:
	unsigned int _ma;
	static int _dem;
	string ngay;
	unsigned int ma_docgia;
	
	int _mang[MAX_BORROW_BOOK];
public:
	unsigned int ma_sach;
	Phieu_muon();
	~Phieu_muon();
	void nhap();
	void xuat();
};

#endif
