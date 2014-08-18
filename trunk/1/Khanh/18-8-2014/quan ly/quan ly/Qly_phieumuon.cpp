#include"qly_phieumuon.h"

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
	if(sl !=0)
		for(int j=0;j<sl;j++)
			for(int k=0; k< phieu[j]->sl_sach; k++)
				for(int l=0; k< phieu[sl]->sl_sach; l++)
					if(phieu[j]->a[k] == phieu[sl]->a[l]) 
						{
							cout<<"ma sach: "<<phieu[sl]->a[l]<<"da dc muon"<<endl;
							phieu[sl]->a[l]=NULL;
							phieu[sl]->sl_sach--;
					}
}
//void Qly_phieumuon::sach_con()
//{
//	cout<<" sach chua muon la: "<<endl;
//	for(int i=0; i< Qly_sach::sl;i++)
//	{
//		if(Qly_sach::qly[i]->tinhtrang== 0);
//