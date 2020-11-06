#include "SACH.h"

void Sach::outputSach()
{
	cout << "MaSach" << "_" << "TieuDe" << "_" << "TacGia" << "_" << "NhaXuatBan" << "_" << "GiaBan" << "_" << "NamPhatHanh" << "_"
		<< "SoTrang" << "_" << "NgayNhapKho" << endl;

	cout << this->_strMaSach << "_" << this->_strTieuDe << "_" << this->_strTacGia << "_" << this->_strNhaXuatBan << "_" << this->_fGiaBan << "_" << this->_iNamPhatHanh << "_"
		<< this->_iSoTrang << "_" << this->NgayNhapKho._iNgay << "/" << this->NgayNhapKho._iThang << "/" << this->NgayNhapKho._iNam << "_" << this->_iTinhTrang << endl;
}

void Sach::writeSach(ofstream& file)
{
	file << this->getMaSach() << "," << this->getTieuDe() << "," << this->getTacGia() << ","
		<< this->getNXB() << "," << this->getGiaBan() << "," << this->getNamPhatHanh() << "," << this->getSoTrang() << ","
		<< this->getNgayNhapKho().getNgay() << "/" << this->getNgayNhapKho().getThang() << "/" << this->getNgayNhapKho().getNam() << ","
		<< this->getTinhTrang() << endl;
}

void Sach::readSach(ifstream& file)
{
	rewind(stdin);
	getline(file, _strMaSach, ',');
	rewind(stdin);
	getline(file, _strTieuDe, ',');
	rewind(stdin);
	getline(file, _strTacGia, ',');
	rewind(stdin);
	getline(file, _strNhaXuatBan, ',');
	file >> _fGiaBan;
	file.ignore(1);
	file >> _iNamPhatHanh;
	file.ignore(1);
	file >> _iSoTrang;
	file.ignore(1);
	file >> NgayNhapKho._iNgay;
	file.ignore(1);
	file >> NgayNhapKho._iThang;
	file.ignore(1);
	file >> NgayNhapKho._iNam;
	file.ignore(1);
	file >> _iTinhTrang;
	file.ignore(1);
}

ostream& operator<<(ostream& os, Sach& sach)
{
	os << sach._strMaSach << "_____" << sach._strTieuDe << "_" << sach._strTacGia << "_" << sach._strNhaXuatBan << "_" << sach._fGiaBan << "_" << sach._iNamPhatHanh << "_" << sach._iSoTrang << "_"
		<< sach.NgayNhapKho.getNgay() << "/" << sach.NgayNhapKho.getThang() << "/" << sach.NgayNhapKho.getNam() << "_" << sach._iTinhTrang << endl;
	return os;
}

void Sach::nhapSachMoi()
{
	cout << "Nhap ma sach: ";
	rewind(stdin);
	getline(cin, _strMaSach);
	cout << "Nhap tieu de sach: ";
	rewind(stdin);
	getline(cin, _strTieuDe);
	cout << "Nhap ten tac gia: ";
	rewind(stdin);
	getline(cin, _strTacGia);
	cout << "Nhap ten nha xuat ban: ";
	rewind(stdin);
	getline(cin, _strNhaXuatBan);
	cout << "Nhap gia ban: ";
	cin >> _fGiaBan;
	cout << "Nhap nam phat hanh: ";
	cin >> _iNamPhatHanh;
	cout << "Nhap so trang: ";
	cin >> _iSoTrang;
	cout << "Nhap ngay nhap kho: ";
	cin >> NgayNhapKho._iNgay;
	cout << "Nhap thang nhap kho: ";
	cin >> NgayNhapKho._iThang;
	cout << "Nhap nam nhap kho: ";
	cin >> NgayNhapKho._iNam;
	cout << "Nhap tinh trang sach(0,1): ";
	cin >> _iTinhTrang;
	ofstream fcout;
	fcout.open("Sach.txt", ios::app);
	fcout << "" << _strMaSach << "," << _strTieuDe
		<< "," << _strTacGia << "," << _strNhaXuatBan
		<< "," << _fGiaBan << "," << _iNamPhatHanh << "," << _iSoTrang
		<< "," << NgayNhapKho._iNgay << "/" << NgayNhapKho._iThang
		<< "/" << NgayNhapKho._iNam << "," << _iTinhTrang << endl;
	fcout.close();
}