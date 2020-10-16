#ifndef ADMIN_H_INCLUDED_
#define ADMIN_H_INCLUDED_
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#pragma once
class Admin
{
private:
	string _strTaiKhoan, _strMatKhau;
public:
	Admin()
	{
		_strTaiKhoan = "";
		_strMatKhau = "";
	}
	Admin(string strTaiKhoan, string strMatKhau)
	{
		this->_strTaiKhoan = strTaiKhoan;
		this->_strMatKhau = strMatKhau;
	}
	string getTaiKhoan();
	string getMatKhau();
	void setTaiKhoan(string strTaiKhoan);
	void setMatKhau(string strMatKhau);
	void setDangNhap(string strTaiKhoan, string strMatKhau);
	void docAd(ifstream& fcin);
	friend ostream& operator << (ostream& os, Admin& ad);
	~Admin() {};
};

#endif