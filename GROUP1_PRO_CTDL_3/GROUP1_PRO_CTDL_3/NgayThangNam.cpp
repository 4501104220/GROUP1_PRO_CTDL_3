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
istream& operator >> (istream& is, Date& D)
{
	cout << "Nhap ngay: ";
	is >> D._iNgay;
	cout << "Nhap thang: ";
	is >> D._iThang;
	cout << "Nhap nam: ";
	is >> D._iNam;
	return is;
}
ostream& operator << (ostream& os, Date& D)
{
	os << D._iNgay << "," << D._iThang << "," << D._iNam << endl;
	return os;
}