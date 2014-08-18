#ifndef class_qlysach
#define class_qlysach
#include "sachGk.h"
#include"sachGt.h"
class Qly_sach
{
public:
	int sl;
	static const int max=100;
	sach *qly[max];
	Qly_sach();
	~Qly_sach();
	void them(sach *s);
	void xuat();
};
#endif