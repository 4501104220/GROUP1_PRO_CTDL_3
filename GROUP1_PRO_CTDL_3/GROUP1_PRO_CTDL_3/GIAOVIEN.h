#ifndef GIAOVIEN_H_INCLUDED_
#define GIAOVIEN_H_INCLUDED_

#include "BANDOC.h"
#pragma once

class GiaoVien :
	public BanDoc
{
private:
	string _strDiaChi, _strSoDT;
public:
	GiaoVien()
	{
		_strDiaChi = "";
		_strSoDT = 1;
	}
	GiaoVien(string strMaBanDoc, string strHoTen, string strKhoa, string strDiaChi, string strSoDT, int iNgay, int iThang, int iNam)
		:BanDoc(strMaBanDoc, strHoTen, strKhoa, iNgay, iThang, iNam)
	{
		this->_strDiaChi = strDiaChi;
		this->_strSoDT = strSoDT;
	}
	string getDiachi();
	string getSoDT();
	void setDiaChi(string strDiaChi);
	void setSoDT(string strSoDT);
	void setGiaoVien(string strDiaChi, string strSoDT);

	void ouputBanDoc();
	friend ostream& operator<<(ostream& os, GiaoVien& gv);
	void nhapGiaoVienMoi();
	void readBanDoc(ifstream& file);
	void writeBanDoc(ofstream& file);
	~GiaoVien() {};
};

#endif