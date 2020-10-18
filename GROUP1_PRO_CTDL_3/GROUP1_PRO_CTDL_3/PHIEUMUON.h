#ifndef _PHIEUMUON_H_INCLUDED_
#define _PHIEUMUON_H_INCLUDED_

#include "SINHVIEN.h"
#include "SACH.h"
#include "GIAOVIEN.h"
#pragma once

class PhieuMuon
{
private:
	static int _i_static_STT;
	int _iSTT = 0;
	Date date;
	BanDoc bandoc;
	Sach sach;
	int _iTinhTrang = 1;
	string _strMaBanDoc_;
	string _strMaSach_;
	int _iNgayMuon = 0;
	int _iThangMuon = 0;
	int _iNamMuon = 0;
	int _iNgayTra = 0;
	int _iThangTra = 0;
	int _iNamTra = 0;
public:
	friend BanDoc;
	friend Sach;
	PhieuMuon() = default;
	PhieuMuon(string _strMaBanDoc, string _strMaSach, int iNgay, int iThang, int iNam)
		:date(iNgay, iThang, iNam), bandoc(_strMaBanDoc), sach(_strMaSach)
	{
		_iTinhTrang = 1;
		this->_i_static_STT++;
	}
	int _TraNgay(int iThang, int iNam);
	void setNgayMuon(int& iNgay, int& iThang, int& iNam);
	void setNgayTra(int& iNgay, int& iThang, int& iNam, int& iNgayTra, int& iThangTra, int& iNamTra);
	bool searchMaSach(string strMaSach);
	void nhapPhieuMuonMoi()
	{
		this->_i_static_STT++;
		cout << "Nhap phieu muon thu: " << _i_static_STT << endl;
		cout << "Nhap ma sach ";
		getline(cin, _strMaSach_);
		cout << "Nhap ma ban doc: ";
		getline(cin, _strMaBanDoc_);
		
		setNgayMuon(_iNgayMuon, _iThangMuon, _iNamMuon);
		setNgayTra(_iNgayMuon, _iThangMuon, _iNamMuon, _iNgayTra, _iThangTra, _iNamTra);
		cout << _iNgayTra << "/" << _iThangTra << "/" << _iNamTra << endl;
		ofstream fcout;
		fcout.open("PhieuMuon.txt", ios::app);
		fcout << _i_static_STT << "#" << _strMaSach_ << "#" << _strMaBanDoc_
			<< "#" << _iNgayMuon << "#" << _iThangMuon
			<< "#" << _iNamMuon << "#" << _iNgayTra
			<< "#" << _iThangTra << "#" << _iNamTra << "#" << _iTinhTrang << endl;
		fcout.close();
	}
	void docThongtin()
	{
		int _iSTT = 0;
		ifstream fcin;
		fcin.open("PhieuMuon.txt");

		fcin >> _iSTT;
		fcin.ignore(1);
		getline(fcin, _strMaSach_, '#');
		getline(fcin, _strMaBanDoc_, '#');
		fcin.ignore(1);
		fcin >> _iNgayMuon;
		fcin.close();
	}
	void readPhieuMuon(ifstream& file)
	{
		file >> _iSTT;
		file.ignore(1);
		rewind(stdin);
		getline(file, _strMaSach_, '#');
		getline(file, _strMaBanDoc_, '#');
		rewind(stdin);
		file >> _iNgayMuon;
		file.ignore(1);
		file >> _iThangMuon;
		file.ignore(1);
		file >> _iNamMuon;
		file.ignore(1);
		file >> _iNgayTra;
		file.ignore(1);
		file >> _iThangTra;
		file.ignore(1);
		file >> _iNamTra;
		file.ignore(1);
		file >> _iTinhTrang;
		file.ignore(1);
	}
	~PhieuMuon() {};
};

#endif