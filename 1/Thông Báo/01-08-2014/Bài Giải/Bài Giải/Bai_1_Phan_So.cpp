class PhanSo_Class
{
public:
	int _tu_so;

	int _mau_so;

	void In_Phan_So()
	{
		cout<<_tu_so<<"/"<<_mau_so<<endl;
	}

	PhanSo_Class Cong_Phan_So(PhanSo_Class phan_so)
	{
		_tu_so=_tu_so*phan_so._mau_so + _mau_so*phan_so._tu_so;
		_mau_so = _mau_so*phan_so._mau_so;
		return *this;
	}

	PhanSo_Class Tru_Phan_So(PhanSo_Class phan_so)
	{
		_tu_so=_tu_so*phan_so._mau_so - _mau_so*phan_so._tu_so;
		_mau_so = _mau_so*phan_so._mau_so;
		return *this;
	}

	PhanSo_Class Nhan_Phan_So(PhanSo_Class phan_so)
	{
		_tu_so = _tu_so*phan_so._tu_so;
		_mau_so=_mau_so*phan_so._mau_so;
		return *this;
	}

	PhanSo_Class Chia_Phan_So(PhanSo_Class phan_so)
	{
		_tu_so = _tu_so*phan_so._mau_so;
		_mau_so=_mau_so*phan_so._tu_so;
		return *this;
	}

};