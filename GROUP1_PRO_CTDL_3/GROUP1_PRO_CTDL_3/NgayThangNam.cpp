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
void Date::setNgay(int iNgay)
{
	this->_iNgay = iNgay;
}
void Date::setThang(int iThang)
{
	this->_iThang = iThang;
}
void Date::setNam(int iNam)
{
	this->_iNam = iNam;
}
void Date::setDate(int iNgay, int iThang, int iNam)
{
	this->_iNgay = iNgay;
	this->_iThang = iThang;
	this->_iNam = iNam;
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