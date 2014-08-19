#ifndef qly_phieu_muon
#define qly_phieu_muon

#include"phieumuon.h"
#include"quanlysach.h"

class Qly_phieumuon
{
private:
	Qly_phieumuon();
public:
	~Qly_phieumuon();
	int so_luong;
	Phieu_muon* _mang[MAX_PHIEU_MUON];
	static Qly_phieumuon* qly_phieumuon;
	void them(Phieu_muon *pmuon);
	void xuat();
	void KiemTra();

};

#endif
