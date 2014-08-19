#ifndef class_qlysach
#define class_qlysach
#include "sachGk.h"
#include"sachGt.h"
class Qly_sach
{
protected:
	static const int max=100;
	Qly_sach();
public:
	int sl;
	sach *qly[max];
	static Qly_sach*qlysach;
	~Qly_sach();
	void them(sach *s);
	void xuat();
};
#endif