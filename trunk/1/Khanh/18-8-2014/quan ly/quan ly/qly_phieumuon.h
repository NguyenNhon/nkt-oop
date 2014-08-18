#ifndef class_qlyphieumuon
#define class_qlyphieumuon
#include"phieumuon.h"
class Qly_phieumuon: public Qly_sach
{
private:
	static const int max=100;
	phieumuon *phieu[max];
	int sl;
public:
	Qly_phieumuon();
	~Qly_phieumuon();
	void them(phieumuon *p);
	void sach_con();
	void sach_het();
};
#endif