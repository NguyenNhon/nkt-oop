#include"sachGK.h"
#include"sachGT.h"
#include"quanlysach.h"

int main()
{
	Quanly_sach *Qly=new Quanly_sach;
	Sach *Nhap;
	Nhap=new Sach_Giaokhoa;
	Nhap->nhap();
	Nhap->xuat();
	Nhap=new Sach_Giaitri;
	Nhap->nhap();
	Nhap->xuat();
	getch();
	return 0;
}