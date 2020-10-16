#ifndef NGAYTHANGNAM_H_INCLUDED_
#define NGAYTHANGNAM_H_INCLUDED_

#include <iostream>
#include <iomanip>
#include <vector>
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNING
#include <ctime>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
using namespace std;
#pragma once
class Sach;
class Bandoc;
class SinhVien;
class GiaoVien;
class Date
{
private:
	int _iNgay, _iThang, _iNam;
public:
	friend Sach;
	friend Bandoc;
	friend GiaoVien;
	friend SinhVien;

	Date()
	{
		time_t rawtime;
		struct tm* info;
		char buffer[80];
		time(&rawtime);
		info = localtime(&rawtime);
		this->_iNgay = (info->tm_mday);
		this->_iThang = (info->tm_mon + 1);
		this->_iNam = (info->tm_year + 1900);
	}
	Date(int iNgay, int iThang, int iNam)
	{
		this->_iNgay = iNgay;
		this->_iThang = iThang;
		this->_iNam = iNam;
	}
	int getNgay();
	int getThang();
	int getNam();
	void setNgay(int iNgay);
	void setThang(int iThang);
	void setNam(int iNam);
	void setDate(int iNgay, int iThang, int iNam);
	void outputNgay();
	friend istream& operator >> (istream& is, Date& d);
	friend ostream& operator << (ostream& os, Date& d);
	virtual ~Date() {};
};

#endif