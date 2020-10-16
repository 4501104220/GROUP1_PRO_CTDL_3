#include "NGAYTHANGNAM.h"
int Date::getNgay()
{
	return this->_iNgay;
}
int Date::getThang()
{
	return this->_iThang;
}
int Date::getNam()
{
	return this->_iNam;
}
void Date::setNgay(int _iNgay)
{
	this->_iNgay = _iNgay;
}
void Date::setThang(int _iThang)
{
	this->_iThang = _iThang;
}
void Date::setNam(int _iNam)
{
	this->_iNam = _iNam;
}
void Date::setDate(int _iNgay, int _iThang, int _iNam)
{
	this->_iNgay = _iNgay;
	this->_iThang = _iThang;
	this->_iNam = _iNam;
}
void Date::outputNgay()
{
	cout << this->_iNgay << "/" << this->_iThang << "/" << this->_iNam << endl;
}
istream& operator >> (istream& is, Date& d)
{
	cout << "Nhap ngay: ";
	is >> d._iNgay;
	cout << "Nhap thang: ";
	is >> d._iThang;
	cout << "Nhap nam: ";
	is >> d._iNam;
	return is;
}
ostream& operator << (ostream& os, Date& d)
{
	os << d._iNgay << "," << d._iThang << "," << d._iNam << endl;
	return os;
}