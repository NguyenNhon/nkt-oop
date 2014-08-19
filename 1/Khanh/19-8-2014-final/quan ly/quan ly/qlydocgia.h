#ifndef class_qlydocgia
#define class_qlydocgia
#include"docgia.h"
class Qly_docgia
{
protected:
	static const int max=100;
	Qly_docgia();
public:
	unsigned int sl;
	docgia* Qly[max];
	static Qly_docgia *qlydocgia;
	~Qly_docgia();
	void them(docgia *d);
	void tinhtrangdocgia();
	void xuat();
};
#endif