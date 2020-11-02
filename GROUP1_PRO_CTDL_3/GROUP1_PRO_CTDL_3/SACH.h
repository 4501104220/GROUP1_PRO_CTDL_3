#ifndef SACH_H_INCLUDED_
#define SACH_H_INCLUDED_

#include "NGAYTHANGNAM.h"
#include <string>
using namespace std;
#pragma once

class Sach
{
private:
	int _iSize;
	string _strMaSach, _strTieuDe, _strTacGia, _strNhaXuatBan;
	float _fGiaBan;
	int _iNamPhatHanh, _iSoTrang;
	Date NgayNhapKho;
	int _iTinhTrang;
public:
	Sach()
	{
		this->_iSize = 0;
		this->_strMaSach = "";
		this->_strTieuDe = "";
		this->_strTacGia = "";
		this->_strNhaXuatBan = "";
		this->_fGiaBan = 0;
		this->_iNamPhatHanh = 0;
		this->_iSoTrang = 0;
		this->_iTinhTrang = 0;
	}
	Sach(string strMaSach):NgayNhapKho()
	{
		this->_iSize = 0;
		this->_strMaSach = strMaSach;
		this->_strTieuDe = "";
		this->_strTacGia = "";
		this->_strNhaXuatBan = "";
		this->_fGiaBan = 0;
		this->_iNamPhatHanh = 0;
		this->_iSoTrang = 0;
		this->_iTinhTrang = 0;
	}
	Sach(int iSize, string strMaSach, string strTieuDe, string strTacGia, string strNhaXuatBan, float fGiaBan, 
		int iNamPhatHanh, int iSoTrang, int iNgay, int iThang, int iNam, int iTinhTrang)
		:NgayNhapKho(iNgay, iThang, iNam)
	{
		this->_iSize = iSize;
		this->_strMaSach = strMaSach;
		this->_strTieuDe = strTieuDe;
		this->_strTacGia = strTacGia;
		this->_strNhaXuatBan = strNhaXuatBan;
		this->_fGiaBan = fGiaBan;
		this->_iNamPhatHanh = iNamPhatHanh;
		this->_iSoTrang = iSoTrang;
		this->_iTinhTrang = 0;
	}
	Sach(int iSize, string strMaSach, string strTieuDe, string strTacGia, string strNhaXuatBan, float fGiaBan, 
		int iNamPhatHanh, int iSoTrang, int iTinhTrang)
	{
		this->_iSize = iSize;
		this->_strMaSach = strMaSach;
		this->_strTieuDe = strTieuDe;
		this->_strTacGia = strTacGia;
		this->_strNhaXuatBan = strNhaXuatBan;
		this->_fGiaBan = fGiaBan;
		this->_iNamPhatHanh = iNamPhatHanh;
		this->_iSoTrang = iSoTrang;
		this->_iTinhTrang = 0;
	}
	int getSize() {
		return this->_iSize;
	}
	string getMaSach()
	{
		return this->_strMaSach;
	}
	string getTieuDe()
	{
		return this->_strTieuDe;
	}
	string getTacGia()
	{
		return this->_strTacGia;
	}
	string getNXB()
	{
		return this->_strNhaXuatBan;
	}
	float getGiaBan()
	{
		return this->_fGiaBan;
	}
	int getNamPhatHanh()
	{
		return this->_iNamPhatHanh;
	}
	int getSoTrang()
	{
		return this->_iSoTrang;
	}
	Date getNgayNhapKho()
	{
		return this->NgayNhapKho;
	}
	int getTinhTrang()
	{
		return this->_iTinhTrang;
	}
	void setTinhTrangSach(int iTinhTrang)
	{
		this->_iTinhTrang = iTinhTrang;
	}
	friend ostream& operator<<(ostream& os, Sach& sach);
	void outputSach();
	void writeSach(ofstream& file);
	void readSach(ifstream& file);
	void nhapSachMoi();
	~Sach() {};
};

#endif