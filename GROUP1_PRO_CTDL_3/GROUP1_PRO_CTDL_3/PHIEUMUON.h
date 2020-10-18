#ifndef _PHIEUMUON_H_INCLUDED_
#define _PHIEUMUON_H_INCLUDED_

#include "SINHVIEN.h"
#include "SACH.h"
#include "GIAOVIEN.h"
#pragma once

class PhieuMuon
{
private:
	static int _i_static_stt;
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
	PhieuMuon(string strMaBanDoc, string strMaSach, int iNgay, int iThang, int iNam)
		:date(iNgay, iThang, iNam), bandoc(strMaBanDoc), sach(strMaSach)
	{
		_iTinhTrang = 1;
		this->_i_static_stt++;
	}
	int _TraNgay(int iThang, int iNam);
	void setNgayMuon(int& iNgayMuon, int& iThangMuon, int& iNamMuon);
	void setNgayTra(int& iNgayMuon, int& iThangMuon, int& iNamMuon, int& iNgayTra, int& iThangTra, int& iNamTra);
	bool searchMaSach(string strMaSach);
	void nhapPhieuMuonMoi()
	{
		this->_i_static_stt++;
		cout << "Nhap phieu muon thu: " << _i_static_stt << endl;
		cout << "Nhap ma sach ";
		getline(cin, _strMaSach_);
		cout << "Nhap ma ban doc: ";
		getline(cin, _strMaBanDoc_);
		
		setNgayMuon(_iNgayMuon, iThangMuon, iNamMuon);
		setNgayTra(iNgayMuon, iThangMuon, iNamMuon, iNgayTra, iThangTra, iNamTra);
		cout << ngaytra << "," << thangtra << "," << namtra << endl;
		ofstream fcout;
		fcout.open("phieumuon.txt", ios::app);
		fcout << _i_static_stt << "#" << masach << "#" << strMaBanDoc
			<< "#" << ngaymuon << "#" << thangmuon
			<< "#" << nammuon << "#" << ngaytra
			<< "#" << thangtra << "#" << namtra << "#" << tinhtrang << endl;
		fcout.close();
	}
	void docThongtin()
	{
		int STT = 0;

		ifstream fcin;
		fcin.open("phieumuon.txt");

		fcin >> STT;
		fcin.ignore(1);
		getline(fcin, masach, '#');
		getline(fcin, strMaBanDoc, '#');
		fcin.ignore(1);
		fcin >> ngaymuon;
		fcin.close();
	}
	void readPhieuMuon(ifstream& file)
	{
		file >> _iSTT;
		file.ignore(1);
		rewind(stdin);
		getline(file, masach, '#');
		getline(file, strMaBanDoc, '#');
		rewind(stdin);
		file >> ngaymuon;
		file.ignore(1);
		file >> thangmuon;
		file.ignore(1);
		file >> nammuon;
		file.ignore(1);
		file >> ngaytra;
		file.ignore(1);
		file >> thangtra;
		file.ignore(1);
		file >> namtra;
		file.ignore(1);
		file >> tinhtrang;
		file.ignore(1);
	}
	~PhieuMuon() {};
};

#endif