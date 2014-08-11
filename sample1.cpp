class A 
{
protected:	
	unsigned int _ma;
	static unsigned int Dem;
public:
	A()
	{
		++Dem;
		_ma=Dem;
	}
};
// Khoi tao gia tri bien Dem ban dau la 0.
unsigned int DocGia::Dem = 0;