#ifndef sach_GK
#define sach_GK
#include"sach.h"

using namespace std;

class Sach_Giaokhoa : public Sach
{
private:
	int lop;
public:
	Sach_Giaokhoa();
	~Sach_Giaokhoa();
	void nhap();
	void xuat();
};

#endif