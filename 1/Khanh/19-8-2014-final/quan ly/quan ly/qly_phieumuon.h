#ifndef class_qlyphieumuon
#define class_qlyphieumuon
#include"phieumuon.h"
class Qly_phieumuon
{
protected:
	static const int max=100;
	Qly_phieumuon();
public:
	phieumuon *phieu[max];
	int sl;
	static Qly_phieumuon *qlyphieumuon;
	~Qly_phieumuon();
	void them(phieumuon *p);
	void sach_con();
	void sach_het();
};
#endif