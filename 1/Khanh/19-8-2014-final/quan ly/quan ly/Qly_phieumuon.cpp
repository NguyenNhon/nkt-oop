#include"qly_phieumuon.h"
Qly_phieumuon *Qly_phieumuon::qlyphieumuon=new Qly_phieumuon();
Qly_phieumuon::Qly_phieumuon()
{
	this->sl=0;
	for(int i=0; i<sl;i++)
		phieu[i]=NULL;
}
Qly_phieumuon::~Qly_phieumuon()
{
	for(int i=0; i<sl;i++)
	{
		if(phieu[i]!=NULL)
		{
			delete phieu[i];
			phieu[i]=NULL;
		}
	}
	delete[] phieu;
}
void Qly_phieumuon::them(phieumuon *p)
{
	if(sl<max) phieu[sl]=p;
	sl++;
}
void Qly_phieumuon::sach_con()
{
	int dem=0;
	cout<<" sach chua muon la: "<<endl;
	for(int i=0; i< Qly_sach::qlysach->sl;i++)
	{
		if(Qly_sach::qlysach->qly[i]->tinhtrang== eTinhTrang::con) 
		{
			dem++;
			cout<<Qly_sach::qlysach->qly[i]->_ma<<endl;
		}
	}
	if(dem==0) cout<<"sach da muon het!"<<endl;
}
void Qly_phieumuon::sach_het()
{
	int dem=0;
	cout<<" sach da muon la: "<<endl;
	for(int i=0; i< Qly_sach::qlysach->sl;i++)
	{
		if(Qly_sach::qlysach->qly[i]->tinhtrang== eTinhTrang::het)
		{
			dem++;
			cout<<Qly_sach::qlysach->qly[i]->_ma<<endl;
		}
	}
	if(dem==0) cout<<"chua co sach nao dc muon!"<<endl;
}
