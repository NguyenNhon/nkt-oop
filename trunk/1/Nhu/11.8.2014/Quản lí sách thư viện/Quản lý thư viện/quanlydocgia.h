#ifndef qly_docgia
#define qly_docgia

#include"docgia.h"

class Qly_docgia
{
private:
	int so_luong;
	Doc_gia* _mang[MAX_READER];
public:
	Qly_docgia();
	~Qly_docgia();
	void them(Doc_gia* docgia);
};

#endif