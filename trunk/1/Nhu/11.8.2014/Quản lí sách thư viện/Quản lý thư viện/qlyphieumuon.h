#ifndef qly_phieumuon
#define qly_phieumuon

#include"phieumuon.h"

class Qly_phieumuon:public Quanly_sach
{
private:
	int so_luong;
	Phieu_muon* _mang[MAX_PHIEU_MUON];
public:
	Qly_phieumuon();
	~Qly_phieumuon();
	void them(Phieu_muon *pmuon);
	void Tinh_trang();
};

#endif
