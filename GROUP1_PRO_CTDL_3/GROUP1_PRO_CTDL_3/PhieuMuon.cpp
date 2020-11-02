#include "PHIEUMUON.h"

int PhieuMuon::_i_static_STT = 1;

int PhieuMuon::_TraNgay(int iThang, int iNam)
{
	if (iThang == 1 || iThang == 3 || iThang == 5 || iThang == 7 || iThang == 8 || iThang == 10 || iThang == 12)
	{
		return 31;
	}
	else
	{
		if (iThang == 2)
		{
			if (iNam % 4 == 0 && iNam % 100 != 0 || iNam % 400 == 0)
			{
				return 29;
			}
			else
			{
				return 28;
			}
		}
		return 30;
	}
	return 0;
}

void PhieuMuon::setNgayMuon(int& iNgay, int& iThang, int& iNam)
{
	time_t now = time(0);
	tm* LocalTime = localtime(&now);
	iNgay = LocalTime->tm_mday;
	iThang = 1 + LocalTime->tm_mon;
	iNam = 1900 + LocalTime->tm_year;
}

void PhieuMuon::setNgayTra(int& iNgay, int& iThang, int& iNam, int& iNgayTra, int& iThangTra, int& iNamTra)
{
	iNamTra = iNam;
	iThangTra = iThang;
	iNgayTra = iNgay;
	if (iThang != 12)
	{
		if (iNgay + 7 > _TraNgay(iThang, iNam))
		{
			iThangTra = iThang + 1;
			iNgayTra = iNgay + 7 - _TraNgay(iThang, iNam);
		}
		else
		{
			iNgayTra = iNgay + 7;
		}
	}
	else
	{
		if (iNgay + 7 > _TraNgay(iThang, iNam))
		{
			iThangTra = 1;
			iNgayTra = iNgay + 7 - _TraNgay(iThang, iNam);
			iNamTra = iNam + 1;
		}
		else
		{
			iNgayTra = iNgay + 7;
		}
	}
}

void PhieuMuon::readPhieuMuon(ifstream& file)
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

ostream& operator<<(ostream& os, PhieuMuon& Pm) {
	os << Pm._iSTT << "_" << Pm._strMaSach_ << "_" << Pm._strMaBanDoc_
		<< "_" << Pm._iNgayMuon << "/" << Pm._iThangMuon
		<< "/" << Pm._iNamMuon << "_" << Pm._iNgayTra
		<< "/" << Pm._iThangTra << "/" << Pm._iNamTra << "_" << Pm._iTinhTrang << endl;
	return os;
}

void PhieuMuon::traSach() {
	cout << "Chan thanh xin loi quy doc gia, he thong chua ho tro viec tra sach!"<<endl;
	cout << "Nhom phat trien se som cap nhap chuc nang nay." << endl;
	cout << "Xin cam on!";

}