#include "GIAOVIEN.h"
#include<string>

string GiaoVien::getDiachi()
{
	return this->_strDiaChi;
}
string GiaoVien::getSoDT()
{
	return this->_strSoDT;
}
void GiaoVien::setDiaChi(string strDiaChi)
{
	this->_strDiaChi = strDiaChi;
}
void GiaoVien::setSoDT(string strSoDT)
{
	this->_strSoDT = strSoDT;
}
void GiaoVien::setGiaoVien(string strDiaChi, string strSoDT)
{
	this->_strDiaChi = strDiaChi;
	this->_strSoDT = strSoDT;
}
void GiaoVien::ouputBanDoc()
{
	cout << "MaBanDoc" << "_" << "HoTen" << "_" <<
		"Khoa" << "_" << "DiaChi" << "_" << "SoDT" << "_" << "NgayThamGia" << "\n";

	cout << this->_strMaBanDoc << "_" << this->_strHoTen << "_" <<
		this->_strKhoa << "_" << this->_strDiaChi << "_" << this->_strSoDT << "_" << this->NgayThamGia._iNgay << "/" << this->NgayThamGia._iThang << "/"
		<< this->NgayThamGia._iNam << "\n";
}
ostream& operator<<(ostream& os, GiaoVien& gv)
{
	os << "MaBanDoc" << "_" << "HoTen" << "_" << "Khoa" << "_" << "DiaChi" << "_"
		<< "SoDT" << "_" << "NgayThamGia" << "\n";

	os << gv._strMaBanDoc << "_" << gv._strHoTen << "_" << gv._strKhoa << "_" << gv._strDiaChi << "_"
		<< gv._strSoDT << "_" << gv.NgayThamGia.getNgay()
		<< "/" << gv.NgayThamGia.getThang() << "/" << gv.NgayThamGia.getNam() << "\n";
	return os;
}
void GiaoVien::readBanDoc(ifstream& file)
{
	rewind(stdin);
	getline(file, this->_strMaBanDoc, ',');
	rewind(stdin);
	getline(file, this->_strHoTen, ',');
	rewind(stdin);
	getline(file, this->_strKhoa, ',');
	rewind(stdin);
	getline(file, this->_strDiaChi, ',');
	rewind(stdin);
	getline(file, this->_strSoDT, ',');
	file >> NgayThamGia._iNgay;
	file.ignore(1);
	file >> NgayThamGia._iThang;
	file.ignore(1);
	file >> NgayThamGia._iNam;
	file.ignore(1);
}
void GiaoVien::writeBanDoc(ofstream& file)
{
	file << this->_strMaBanDoc << "," << this->_strHoTen << "," <<
		this->_strKhoa << "," << this->_strDiaChi << "," << this->_strSoDT << "," << this->NgayThamGia._iNgay 
		<< "/" << this->NgayThamGia._iThang 
		<< "/" << this->NgayThamGia._iNam;
}

void GiaoVien::nhapGiaoVienMoi()
{
	cout << "Nhap ma giao vien: ";
	rewind(stdin);
	getline(cin, _strMaBanDoc);
	cout << "Nhap ho ten giao vien: ";
	rewind(stdin);
	getline(cin, _strHoTen);
	cout << "Nhap khoa giao vien: ";
	rewind(stdin);
	getline(cin, _strKhoa);
	cout << "Nhap dia chi: ";
	rewind(stdin);
	getline(cin, _strDiaChi);
	cout << "Nhap so dien thoai: ";
	cin >> _strSoDT;
	cout << "Nhap ngay: ";
	cin >> NgayThamGia._iNgay;
	cout << "Nhap thang: ";
	cin >> NgayThamGia._iThang;
	cout << "Nhap nam: ";
	cin >> NgayThamGia._iNam;
	cout << endl;
	ofstream fcout;
	fcout.open("GiaoVien.txt", ios::app);
	fcout << "" << _strMaBanDoc << "," << _strHoTen << "," << _strKhoa 
		<< "," << _strDiaChi << "," << _strSoDT << "," << NgayThamGia._iNgay 
		<< "/" << NgayThamGia._iThang 
		<< "/" << NgayThamGia._iNam << endl;
	fcout.close();
}