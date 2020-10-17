#ifndef SINHVIEN_H_INCLUDED_
#define SINHVIEN_H_INCLUDED_

#include "BANDOC.h"
#pragma once

class SinhVien :
	public BanDoc
{
private:
	string _strKhoaHoc;
public:
	SinhVien()
	{
		_strKhoaHoc = "";
	}
	SinhVien(string strKhoaHoc)
	{
		this->_strKhoaHoc = strKhoaHoc;
	}
	SinhVien(string strMaBanDoc, string strHoTen, string strKhoa, string strKhoaHoc, int iNgay, int iThang, int iNam)
		:BanDoc(strMaBanDoc, strHoTen, strKhoa, iNgay, iThang, iNam)
	{
		this->_strKhoaHoc = strKhoaHoc;
	}
	string getKhoaHoc();
	void setKhoaHoc(string strKhoaHoc);
	void ouputBanDoc();
	friend ostream& operator<<(ostream& os, SinhVien& sv);
	void nhapSinhVienMoi();

	void readBanDoc(ifstream& file);
	void writeBanDoc(ofstream& file);
	~SinhVien() {};
};

#endif