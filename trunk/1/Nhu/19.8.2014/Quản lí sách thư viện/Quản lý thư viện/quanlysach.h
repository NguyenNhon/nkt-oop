#ifndef quan_ly
#define quan_ly

#include"sachGK.h"
#include"sachGT.h"

class Quanly_sach
{
private:
	Quanly_sach();
public:
	int so_luong;
	Sach* _mang[MAX_BOOK];
	~Quanly_sach();
	void them(Sach *sach);
	void xuat();
	void DanhSachSachCon();
	void DanhSachSachDaMuon();
	void TimSach(unsigned int maSach);
	static Quanly_sach* qly_sach;
};

#endif
