#ifndef BANDOC_H_INCLUDED_
#define BANDOC_H_INCLUDED_

#include "NGAYTHANGNAM.h"
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;
#pragma once

class BanDoc
{
protected:
	string _strHoTen, _strKhoa, _strMaBanDoc;
	Date NgayThamGia;
public:
	BanDoc()
	{
		this->_strHoTen = "";
		this->_strKhoa = "";
		this->_strMaBanDoc = "";
	}
	BanDoc(string strMaBanDoc) {
		this->_strHoTen = "";
		this->_strKhoa = "";
		this->_strMaBanDoc = strMaBanDoc;
	}
	BanDoc(string strMaBanDoc, string strHoTen, string strKhoa, int iNgay, int iThang, int iNam) : NgayThamGia(iNgay, iThang, iNam)
	{
		this->_strHoTen = strHoTen;
		this->_strKhoa = strKhoa;
		this->_strMaBanDoc = strMaBanDoc;
	}
	string getHovaten();
	string getKhoa();
	string getMaBanDoc();
	void setHovaten(string strHoTen);
	void setKhoa(string strKhoa);
	void setMaBanDoc(string strMaBanDoc);
	void setBandoc(string strHoTen, string strKhoa, string strMaBanDoc);

	virtual void inputBanDoc() {}
	virtual void ouputBanDoc() {};
	virtual void readBanDoc(ifstream& file) {};
	virtual void writeBanDoc(ofstream& file) {};
	virtual ~BanDoc() {};
};

#endif