#ifndef BIEN_TOAN_CUC_H
#define BIEN_TOAN_CUC_H

// Define all needed enum

enum LoaiSach
{
	SachGiaoKhoa = 1,
	SachGiaiTri = 2
};
enum TinhTrangSach
{
	Con,
	Het
};
enum LinhVuc
{
	MyThuat = 1,
	AmNhac = 2,
	Truyen = 3
};
enum LoaiDocGia
{
	ThieuNhi = 1, 
	ThieuNien = 2,
	TrungNien = 3
};
enum Lop
{
	MauGiao = 0, 
	Lop1 = 1, 
	Lop2 = 2, 
	Lop3 = 3, 
	Lop4 = 4, 
	Lop5 = 5, 
	Lop6 = 6, 
	Lop7 = 7, 
	Lop8 = 8, 
	Lop9 = 9, 
	Lop10 = 10, 
	Lop11 = 11, 
	Lop12 = 12
};

// Define rules
#define MAX_BOOK 100
#define MAX_READER 100
#define MAX_BORROW_BOOK 5
#define MAX_PHIEU_MUON 100

#endif