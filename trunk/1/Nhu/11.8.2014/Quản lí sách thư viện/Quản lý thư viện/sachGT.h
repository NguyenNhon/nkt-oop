#ifndef sach_GT
#define sach_GT
#include"sach.h"

class Sach_Giaitri : public Sach
{
private:
	int lv;
public:
	Sach_Giaitri();
	~Sach_Giaitri();
	void nhap();
	void xuat();
};

#endif