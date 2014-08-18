#ifndef quan_ly
#define quan_ly
#include"sach.h"

class Quanly_sach
{
public:
	virtual int so_luong;
	virtual Sach* _mang[MAX_BOOK];
	Quanly_sach();
	~Quanly_sach();
	void them(Sach *sach);
};

#endif
