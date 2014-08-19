#ifndef Qly_thuvien
#define Qly_thuvien
#include"quanlysach.h"
#include"qlyphieumuon.h"
#include"quanlydocgia.h"

class Qly_ThuVien
{
public:
	Qly_ThuVien();
	~Qly_ThuVien();
	void themSach();
	void themDocGia();
	void MuonSach();
	void InDSSach();
	void InDSDocGia();
	void InDSSachCon();
	void InDSSachDaMuon();
	void InDanhSachDocGiaMuonSach();
	void TraCuuDocGia();
	void TraCuuSach();
};


#endif