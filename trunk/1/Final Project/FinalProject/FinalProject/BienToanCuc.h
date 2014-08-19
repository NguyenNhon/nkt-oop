#ifndef BIEN_TOAN_CUC_H
#define BIEN_TOAN_CUC_H

#include<string>
#include<iostream>
using namespace std;

// Define all needed enum
enum eLoaiSach
{
	eSachGiaoKhoa = 1,
	eSachGiaiTri = 2
};
enum eLinhVuc
{
	eMyThuat = 1,
	eAmNhac = 2,
	eTruyen = 3
};
enum eLoaiDocGia
{
	eThieuNhi = 1, 
	eThieuNien = 2,
	eTrungNien = 3
};
enum eLop
{
	eMauGiao = 0, 
	eLop1 = 1, 
	eLop2 = 2, 
	eLop3 = 3, 
	eLop4 = 4, 
	eLop5 = 5, 
	eLop6 = 6, 
	eLop7 = 7, 
	eLop8 = 8, 
	eLop9 = 9, 
	eLop10 = 10, 
	eLop11 = 11, 
	eLop12 = 12
};

enum eTinhTrang
{
	eCon,
	eHet
};
// Define rules
#define MAX_BOOK 100
#define MAX_READER 100
#define MAX_BORROW_BOOK 5
#define MAX_PHIEU_MUON 100
#endif