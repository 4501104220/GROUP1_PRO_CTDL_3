#include "ADMIN.h"

string Admin::getTaiKhoan()
{
	return this->_strTaiKhoan;
}
string Admin::getMatKhau()
{
	return this->_strMatKhau;
}
void Admin::setTaiKhoan(string strTaiKhoan)
{
	this->_strTaiKhoan = strTaiKhoan;
}
void Admin::setMatKhau(string strMatKhau)
{
	this->_strMatKhau = strMatKhau;
}
void Admin::setDangNhap(string strTaiKhoan, string strMatKhau)
{
	this->_strTaiKhoan = strTaiKhoan;
	this->_strMatKhau = strMatKhau;
}
void Admin::docAd(ifstream& fcin)
{
	rewind(stdin);
	getline(fcin, _strTaiKhoan, '#');
	rewind(stdin);
	getline(fcin, _strMatKhau);
}
ostream& operator << (ostream& os, Admin& ad)
{
	os << "Tai Khoan: " << ad._strTaiKhoan << endl;
	os << "Mat Khau: " << ad._strMatKhau << endl;
	return os;
}