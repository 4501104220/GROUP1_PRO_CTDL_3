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
	time_t HienTai = time(0);
	tm* LocalTime = localtime(&HienTai);
	iNgay = LocalTime->tm_mday;
	iThang = 1 + LocalTime->tm_mon;
	iNam = 1900 + LocalTime->tm_year;
}

void PhieuMuon::setNgayTra(int& iNgay, int& iThang, int& iNam, int& iNgayTra, int& iThangTra, int& iNamTra)
{
	iNamTra = iNam;
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