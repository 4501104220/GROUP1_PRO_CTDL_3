#include "SINHVIEN.h"

string SinhVien::getKhoaHoc()
{
	return this->_strKhoaHoc;
}
void SinhVien::setKhoaHoc(string strKhoaHoc)
{
	this->_strKhoaHoc = strKhoaHoc;
}
void SinhVien::ouputBanDoc()
{
	cout << "MaBanDoc" << "_" << "HoTen" << "_" <<
		"Khoa" << "_" << "KhoaHoc" << "_" << "NgayThamGia" << "\n";

	cout << this->_strMaBanDoc << "_" << this->_strHoTen << "_" <<
		this->_strKhoa << "_" << this->_strKhoaHoc << "_" << this->NgayThamGia._iNgay << "/" << 
		this->NgayThamGia._iThang << "/" << this->NgayThamGia._iNam << "\n";
}
ostream& operator<<(ostream& os, SinhVien& sv)
{
	os << "MaBanDoc" << "_" << "HoTen" << "_" << "Khoa" << "_" << "KhoaHoc"
		<< "_" << "NgayThamGia" << "\n";

	os << sv._strMaBanDoc << "_" << sv._strHoTen << "_" << sv._strKhoa << "_" << sv._strKhoaHoc
		<< "_" << sv.NgayThamGia.getNgay()
		<< "/" << sv.NgayThamGia.getThang() << "/" << sv.NgayThamGia.getNam() << "\n";
	return os;
}
void SinhVien::nhapSinhVienMoi()
{
	cout << "Nhap ma sinh vien: ";
	rewind(stdin);
	getline(cin, _strMaBanDoc);
	cout << "Nhap ho ten sinh vien: ";
	rewind(stdin);
	getline(cin, _strHoTen);
	cout << "Nhap khoa cua sinh vien: ";
	rewind(stdin);
	getline(cin, _strKhoa);
	cout << "Nhap khoa hoc cua sinh vien: ";
	rewind(stdin);
	getline(cin, _strKhoaHoc);
	cout << "Nhap ngay: ";
	cin >> NgayThamGia._iNgay;
	cout << "Nhap thang: ";
	cin >> NgayThamGia._iThang;
	cout << "Nhap nam: ";
	cin >> NgayThamGia._iNam;
	cout << endl;
	ofstream fcout;
	fcout.open("SinhVien.txt", ios::app);
	fcout << "" << _strMaBanDoc << "," << _strHoTen << "," << _strKhoa << ","
		<< "," << NgayThamGia._iNgay << "/" << NgayThamGia._iThang
		<< "/" << NgayThamGia._iNam << endl;
	fcout.close();
}
void SinhVien::readBanDoc(ifstream& file)
{
	rewind(stdin);
	getline(file, this->_strMaBanDoc, ',');
	rewind(stdin);
	getline(file, this->_strHoTen, ',');
	rewind(stdin);
	getline(file, this->_strKhoa, ',');
	rewind(stdin);
	getline(file, this->_strKhoaHoc, ',');
	file >> NgayThamGia._iNgay;
	file.ignore(1);
	file >> NgayThamGia._iThang;
	file.ignore(1);
	file >> NgayThamGia._iNam;
	file.ignore(1);
}
void SinhVien::writeBanDoc(ofstream& file)
{
	file << this->_strMaBanDoc << "," << this->_strHoTen << "," << this->_strKhoa 
		<< "," << this->_strKhoaHoc << "," << this->NgayThamGia._iNgay 
		<< "," << this->NgayThamGia._iThang << "," << this->NgayThamGia._iNam;
}