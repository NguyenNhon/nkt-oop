#ifndef class_qlydocgia
#define class_qlydocgia
#include"docgia.h"
class Qly_docgia
{
private:
	static const int max=100;
	docgia* Qly[max];
	unsigned int sl;
public:
	Qly_docgia();
	~Qly_docgia();
	void them(docgia *d);
	void xuat();
};
#endif