#include "ADMIN.h"
#include "NGAYTHANGNAM.h"
#include "SACH.h"
#include "GIAOVIEN.h"
#include "SINHVIEN.h"
#include "PHIEUMUON.h"
#include <vector>
#include <conio.h>
#include <windows.h>
/**********************************************************
* @Description Remove warnings when running the program
**********************************************************/
#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS
/**********************************************************
* @Description Set colored text 
* @return Text color
**********************************************************/
void SetColor(int ForgC);
/**********************************************************
* @Description Menu
**********************************************************/
void menuChinh();
void menu();
/**********************************************************
* @Description Admin
**********************************************************/
void docTKvaMK();
bool kiemTraDN(string strTaikhoan, string strMatkhau);
void login();
string maHoaMK(unsigned int maxLength);
/**********************************************************
* @Description Book
**********************************************************/
void docDSSach(vector<Sach>& S);
void xuatDSSach(vector<Sach> S);
void ghiDSSach(vector<Sach> S);
int kTraSach(string strTieuDe);
void timSach();
bool tinhTrangSach(string strMaSach);
void xoaSach();
/**********************************************************
* @Description Reader
**********************************************************/
void docDSSV(vector <SinhVien>& Sv);
void xuatDSSV(vector <SinhVien> Sv);
void docDSGV(vector <GiaoVien>& Gv);
void xuatDSGV(vector <GiaoVien> Gv);
void docDSPhieuMuon(vector <PhieuMuon>& Pm);
void xuatDSPhieuMuon(vector <PhieuMuon> Pm);
int kTraBanDocGV(vector<GiaoVien> Gv, string strMaBanDoc);
void timBanDocGV();
int kTraBanDocSV(string strMaBanDoc);
void timBanDocSV();
void timBanDoc();
/**********************************************************
* @Description Search
**********************************************************/
void timKiemThongtin();
/**********************************************************
* @Description Manage
**********************************************************/
void quanLyThuVien();
void quanLyBanDoc();
void quanLySach();
void quanLyPhieuMuon();
/**********************************************************
* @Description Statistics
**********************************************************/
void tongSachMuon();
void tongSachChuaMuon();
void thongKe();
/**********************************************************
* @Description Declare some variables
**********************************************************/
vector <Admin> Ad;
vector <Sach> S;
vector <GiaoVien> Gv;
vector <SinhVien> Sv;
vector <PhieuMuon> Pm;
/**********************************************************
* @Description Main program
**********************************************************/
void main()
{
	docDSSach(S);
	docTKvaMK();
	docDSGV(Gv);
	docDSSV(Sv);
	docDSPhieuMuon(Pm);
	menuChinh();
	ghiDSSach(S);
	system("pause");
}
/**********************************************************
* @Description UI menu_ user interface menu
**********************************************************/
void menu()
{
	SetColor(11);
	cout << "______________________MENU___________________\n";
	cout << "*********************************************\n";
	SetColor(14);
	cout << "\t 1. HIEN THI THONG TIN SACH \t\n";
	cout << "\t 2. HIEN THI THONG TIN BAN DOC \t\n";
	cout << "\t 3. TIM KIEM THONG TIN \t\n";
	cout << "\t 4. QUAN LY \t\n";
	cout << "\t 5. THOAT! \t\n";
	SetColor(11);
	cout << "*********************************************\n";
}
/**********************************************************
* @Description Main menu
**********************************************************/
void menuChinh()
{
	int iChon = 0;
	do {
		system("cls");
		menu();
		SetColor(10);
		cout << "\tBan hay chon chuc nang: ";
		cin >> iChon;
		switch (iChon)
		{
		case 1:
			system("cls");
			xuatDSSach(S);
			system("pause");
			break;
		case 2:
			system("cls");
			xuatDSGV(Gv);
			cout << endl;
			xuatDSSV(Sv);
			cout << endl;
			system("pause");
			break;
		case 3:
			system("cls");
			timKiemThongtin();
			break;
		case 4:
			system("cls");
			login();
			break;
		default:
			SetColor(14);
			cout << "BAN DA CHON THOAT CHUONG TRINH!\n";
			Sleep(1000);
			exit(0);
		}
	} while (iChon >= 1 && iChon <= 4);
}
/**********************************************************
* @Description Read file Sach.txt
**********************************************************/
void docDSSach(vector<Sach>& S)
{
	ifstream fcin;
	int iSize = 0;
	fcin.open("Sach.txt");
	Sach s;
	fcin >> iSize;
	fcin.ignore(1);
	for (int i = 0; i < iSize; i++)
	{
		s.readSach(fcin);
		S.push_back(s);
	}
	fcin.close();
}
/**********************************************************
* @Description Output book
**********************************************************/
void xuatDSSach(vector<Sach> S)
{
	SetColor(11);
	cout << "----------DANH SACH CAC LOAI SACH CO TRONG THU VIEN----------\n";
	cout << "MaSach" << "_" << "TieuDe" << "_" << "TacGia" << "_" << "NhaXuatBan" << "_" << "GiaBan" << "_" << "NamPhatHanh" << "_" << "SoTrang" << "_"
		<< "NgayNhapKho" << "_" << "TinhTrang" << endl;
	for (int i = 0; i < S.size(); i++)
	{
		cout << S[i];
	}
}
/**********************************************************
* @Description Output teacher
**********************************************************/
void xuatDSGV(vector <GiaoVien> Gv)
{
	SetColor(11);
	SinhVien sv;
	cout << "----------DANH SACH BAN DOC LA GIAO VIEN----------\n";
	cout << "MaBanDoc" << "_" << "HoTen" << "_" << "Khoa" << "_" << "DiaChi" << "_"
		<< "SoDT" << "_" << "NgayThamGia" << "\n";
	for (int i = 0; i < Gv.size(); i++)
	{
		cout << Gv[i];
	}
}
/**********************************************************
* @Description Write file GiaoVien.txt
**********************************************************/
void docDSGV(vector <GiaoVien>& Gv)
{
	ifstream fcin;
	int iSize = 0;
	fcin.open("GiaoVien.txt");
	fcin >> iSize;
	fcin.ignore(1);
	GiaoVien gv;
	for (int i = 0; i < iSize; i++)
	{
		gv.readBanDoc(fcin);
		Gv.push_back(gv);
	}
}
/**********************************************************
* @Description Read file SinhVien.txt
**********************************************************/
void docDSSV(vector <SinhVien>& Sv)
{
	ifstream fcin;
	int iSize = 0;
	fcin.open("SinhVien.txt");
	fcin >> iSize;
	fcin.ignore(1);
	SinhVien sv;
	for (int i = 0; i < iSize; i++)
	{
		sv.readBanDoc(fcin);
		Sv.push_back(sv);
	}
}
/**********************************************************
* @Description Output student
**********************************************************/
void xuatDSSV(vector <SinhVien> Sv)
{
	SetColor(11);
	SinhVien sv;
	cout << "----------DANH SACH BAN DOC LA SINH VIEN----------\n";
	cout << "MaBanDoc" << "_" << "HoTen" << "_" <<
		"Khoa" << "_" << "KhoaHoc" << "_" << "NgayThamGia" << "\n";
	for (int i = 0; i < Sv.size(); i++)
	{
		cout << Sv[i];
	}
}
/**********************************************************
* @Description Search book and reader
**********************************************************/
void timKiemThongtin()
{
	int itimKiem = 0;
	do {
		SetColor(11);
		cout << "___________________TIM KIEM__________________\n";
		cout << "*********************************************\n";
		SetColor(14);
		cout << "\t 1. TIM KIEM SACH \t\n";
		cout << "\t 2. TIM KIEM BAN DOC \t\n";
		cout << "\t 3. THOAT! \t\n";
		SetColor(11);
		cout << "*********************************************\n";
		cout << "Chon chuc nang can tim: ";
		cin >> itimKiem;
		switch (itimKiem)
		{
		case 1:
			timSach();
		case 2:
			system("cls");
			timBanDoc();
		default:
			cout << "BAN CHON THOAT TIM KIEM!\n";
			Sleep(1000);
			system("cls");
			menu();
			menuChinh();
			break;
		}
	} while (itimKiem >= 1 && itimKiem >= 3);
}
/**********************************************************
* @Description Search book
**********************************************************/
void timSach()
{
	string strTieuDe = "";
	SetColor(11);
	cout << "\tNHAP TUA DE SACH: ";
	rewind(stdin);
	getline(cin, strTieuDe);
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTieuDe() == strTieuDe)
		{
			SetColor(14);
			cout << S[i];
			cout << endl;
			break;
		}
	}
	if (kTraSach(strTieuDe) == -1)
	{
		SetColor(12);
		cout << "TUA DE SACH NHAP SAI HOAC SACH KHONG TON TAI TRONG HE THONG !!!\nNHAN ENTER DE QUAY LAI MAN HINH TIM KIEM THONG TIN\n";
	}
	system("pause");
	system("cls");
	timKiemThongtin();
}
/**********************************************************
* @Description Test info book after search
**********************************************************/
int kTraSach(string strTieuDe)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTieuDe() == strTieuDe)
		{
			return i;
		}
	}
	return -1;
}
/**********************************************************
* @Description Search reader
**********************************************************/
void timBanDoc()
{
	int itimKiem = 0;
	SetColor(11);
	cout << "_______________TIM KIEM BAN DOC______________\n";
	cout << "*********************************************\n";
	SetColor(14);
	cout << "\t 1. BAN DOC GIAO VIEN \t\n";
	cout << "\t 2. BAN DOC SINH VIEN \t\n";
	cout << "\t 3. THOAT \t\n";
	SetColor(11);
	cout << "*********************************************\n";
	cout << "Chon ban doc can tim: ";
	cin >> itimKiem;
	switch (itimKiem)
	{
	case 1:
		timBanDocGV();
	case 2:
		timBanDocSV();
	case 3:
		cout << "BAN CHON THOAT TIM KIEM BAN DOC\n";
		Sleep(1000);
		system("cls");
		timKiemThongtin();
		break;
	default:
		system("cls");
		timBanDoc();
	}
}
/**********************************************************
* @Description Search teacher
**********************************************************/
void timBanDocGV()
{
	string strMaBanDoc = "";
	SetColor(11);
	cout << "\tNHAP MA BAN DOC GIAO VIEN: ";
	rewind(stdin);
	getline(cin, strMaBanDoc);
	for (int i = 0; i < Gv.size(); i++)
	{
		if (Gv[i].getMaBanDoc() == strMaBanDoc)
		{
			SetColor(14);
			cout << Gv[i];
			cout << endl;
			break;
		}
	}
	if (kTraBanDocGV(Gv, strMaBanDoc) == -1)
	{
		SetColor(12);
		cout << "MA BAN DOC NHAP SAI HOAC BAN DOC KHONG TON TAI TRONG HE THONG !!!\nNHAN ENTER DE QUAY LAI MAN HINH TIM KIEM THONG TIN\n";
	}
	system("pause");
	system("cls");
	timBanDoc();
}
/**********************************************************
* @Description Test info teacher after search
**********************************************************/
int kTraBanDocGV(vector<GiaoVien> Gv, string strMaBanDoc)
{
	for (int i = 0; i < Gv.size(); i++)
	{
		if (Gv[i].getMaBanDoc() == strMaBanDoc)
		{
			return i;
		}
	}
	return -1;
}
/**********************************************************
* @Description Search student
**********************************************************/
void timBanDocSV()
{
	string strMaBanDoc = "";
	SetColor(11);
	cout << "\tNHAP MA BAN DOC SINH VIEN: ";
	rewind(stdin);
	getline(cin, strMaBanDoc);
	for (int i = 0; i < Sv.size(); i++)
	{
		if (Sv[i].getMaBanDoc() == strMaBanDoc)
		{
			SetColor(14);
			cout << Sv[i];
			cout << endl;
			break;
		}
	}
	if (kTraBanDocSV(strMaBanDoc) == -1)
	{
		SetColor(12);
		cout << "MA BAN DOC NHAP SAI HOAC BAN DOC KHONG TON TAI TRONG HE THONG !!!\nNHAN ENTER DE QUAY LAI MAN HINH TIM KIEM THONG TIN\n";
	}
	system("pause");
	system("cls");
	timBanDoc();
}
/**********************************************************
* @Description Test info student after search
**********************************************************/
int kTraBanDocSV(string strMaBanDoc)
{
	for (int i = 0; i < Sv.size(); i++)
	{
		if (Sv[i].getMaBanDoc() == strMaBanDoc)
		{
			return i;
		}
	}
	return -1;
}
/**********************************************************
* @Description Login account
**********************************************************/
void login()
{
	int idem = 0;
	while (idem < 3)
	{
		string strTaiKhoan = "", strMatKhau = "";
		SetColor(11);
		cout << "*********************************\n";
		SetColor(11);
		cout << "*";
		SetColor(14);
		cout << "\tDANG NHAP QUAN LY\t";
		SetColor(11);
		cout << "*\n";
		SetColor(11);
		cout << "*********************************\n";
		SetColor(14);
		cout << "Nhap tai khoan: ";
		rewind(stdin);
		getline(cin, strTaiKhoan);
		cout << "Nhap mat khau: ";
		strMatKhau = maHoaMK(6);
		if (kiemTraDN(strTaiKhoan, strMatKhau) == true)
		{
			cout << "\nDANG NHAP THANH CONG!\n";
			Sleep(1000);
			quanLyThuVien();
		}
		else
		{
			SetColor(12);
			cout << "\nBAN DA NHAP SAI! VUI LONG NHAP LAI!!\n";
			idem++;
			if (idem == 3)
			{
				cout << "\nBAN DA NHAP SAI QUA 3 LAN! XIN VUI LONG THU LAI SAU!\n" << endl;
				Sleep(1000);
				system("cls");
				menu();
				menuChinh();
			}
			system("pause");
			system("cls");
		}
	}
}
/**********************************************************
* @Description Password encryption
**********************************************************/
string maHoaMK(unsigned int maxLength)
{
	string strpassword = "";
	for (char c; (c = _getch()); )
	{
		if (c == '\n' || c == '\r')
		{
			cout << "\n";
			break;
		}
		else if (c == '\b')
		{
			cout << "\b \b";
			if (!strpassword.empty())
				strpassword.erase(strpassword.size() - 1);
		}
	else if (c == -32)
		{
			return;
		}
		else if (isprint(c) && strpassword.size() < maxLength)
		{
			cout << '*';
			strpassword += c;
		}
	}
	return strpassword;
}
/**********************************************************
* @Description Checking login
**********************************************************/
bool kiemTraDN(string strTaikhoan, string strMatkhau)
{
	for (int i = 0; i < Ad.size(); i++)
	{
		if (Ad[i].getTaiKhoan() == strTaikhoan && Ad[i].getMatKhau() == strMatkhau)
		{
			return true;
		}
	}
	return false;
}
/**********************************************************
* @Description Read file Admin.txt
**********************************************************/
void docTKvaMK()
{
	ifstream fcin;
	int iSize = 0;
	fcin.open("Admin.txt");
	Admin Admin;
	fcin >> iSize;
	fcin.ignore(1);
	for (int i = 0; i < iSize; i++)
	{
		Admin.docAd(fcin);
		Ad.push_back(Admin);
	}
	fcin.close();
}
/**********************************************************
* @Description Manage library after login successful
**********************************************************/
void quanLyThuVien()
{
	int iQuanly = 0;
	do
	{
		system("cls");
		SetColor(11);
		cout << "_______________QUAN LY THU VIEN______________\n";
		cout << "*********************************************\n";
		SetColor(14);
		cout << "\t 1. QUAN LY PHIEU MUON \t\n";
		cout << "\t 2. QUAN LY SACH \t\n";
		cout << "\t 3. QUAN LY BAN DOC \t\n";
		cout << "\t 4. THONG KE \t\n";
		cout << "\t 5. THOAT \t\n";
		SetColor(11);
		cout << "*********************************************\n";
		SetColor(14);
		cout << "Ban hay chon chuc nang can quan ly: ";
		cin >> iQuanly;
		switch (iQuanly)
		{
		case 1:
			system("cls");
			quanLyPhieuMuon();
			system("cls");
			break;
		case 2:
			system("cls");
			quanLySach();
			system("cls");
			break;
		case 3:
			system("cls");
			quanLyBanDoc();
			system("cls");
			break;
		case 4:
			thongKe();
			break;
		default:
			cout << "BAN CHON THOAT QUAN LY!\n";
			Sleep(1000);
			system("cls");
			menu();
			menuChinh();
			break;
		}
	} while (iQuanly >= 1 && iQuanly <= 4);
}
/**********************************************************
* @Description Manage book loan
**********************************************************/
void quanLyPhieuMuon()
{
	PhieuMuon pm;
	ofstream fcout;
	ifstream fcin;
	int iSize = 0;
	fcin.open("PhieuMuon.txt");
	fcin >> iSize;
	fcin.ignore(1);
	int iQuanly = 0;
	do {
		SetColor(11);
		cout << "________________QUAN LY PHIEU MUON______________\n";
		cout << "*********************************************\n";
		SetColor(14);
		cout << "\t 1. XEM DANH SACH PHIEU MUON \t\n";
		cout << "\t 2. TAO PHIEU MUON MOI \t\n";
		cout << "\t 3. TRA SACH \t\n";
		cout << "\t 4. THOAT \t\n";
		SetColor(11);
		cout << "*********************************************\n";
		SetColor(14);
		cout << "Ban hay chon chuc nang can quan ly: ";
		cin >> iQuanly;
		switch (iQuanly)
		{
		case 1:
			system("cls");
			xuatDSPhieuMuon(Pm);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			pm.nhapPhieuMuonMoi();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			pm.traSach();
			system("pause");
			system("cls");
			break;
		default:
			cout << "BAN CHON THOAT QUAN LY PHIEU MUON!\n";
			Sleep(1000);
			system("cls");
			quanLyThuVien();
			break;
		}
	} while (iQuanly >= 1 && iQuanly <= 3);
}
/**********************************************************
* @Description Read file PhieuMuon.txt
**********************************************************/
void docDSPhieuMuon(vector <PhieuMuon>& Pm) 
{
	{
		ifstream fcin;
		int iSize = 0;
		fcin.open("PhieuMuon.txt");
		fcin >> iSize;
		fcin.ignore(1);
		PhieuMuon pm;
		for (int i = 0; i < iSize; i++)
		{
			pm.readPhieuMuon(fcin);
			Pm.push_back(pm);
		}
	}
}
/**********************************************************
* @Description Output book loan
**********************************************************/
void xuatDSPhieuMuon(vector <PhieuMuon> Pm)
{
	SetColor(11);
	cout << "--------------DANH SACH PHIEU MUON----------------\n";
	cout << "STT" << "_" << "MaSach" << "_" << "MaBanDoc"
		<< "_" << "NgayMuon" << "_" << "ThangMuon"
		<< "_" << "NamMuon" << "_" << "NgayTra"
		<< "_" << "ThangTra" << "_" << "NamTra" << "_" << "TinhTrang" << endl;
	for (int i = 0; i < Pm.size(); i++)
	{
		cout << Pm[i];
	}
}
/**********************************************************
* @Description Manage book
**********************************************************/
void quanLySach()
{
	Sach s;
	ofstream fcout;
	ifstream fcin;
	int iSize = 0;
	fcin.open("Sach.txt");
	fcin >> iSize;
	fcin.ignore(1);
	int iQuanly = 0;
	do {
		SetColor(11);
		cout << "__________________QUAN LY SACH_______________\n";
		cout << "*********************************************\n";
		SetColor(14);
		cout << "\t 1. XEM DANH SACH SACH \t\n";
		cout << "\t 2. THEM SACH MOI \t\n";
		cout << "\t 3. XOA SACH \t\n";
		cout << "\t 4. THOAT \t\n";
		SetColor(11);
		cout << "*********************************************\n";
		SetColor(14);
		cout << "Ban hay chon chuc nang can quan ly: ";
		cin >> iQuanly;
		switch (iQuanly)
		{
		case 1:
			system("cls");
			xuatDSSach(S);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			s.nhapSachMoi();
			system("pause");
			system("cls");
			break;
		case 3:
			xoaSach();
			break;
		default:
			cout << "BAN CHON THOAT QUAN LY SACH!\n";
			Sleep(1000);
			system("cls");
			quanLyThuVien();
			break;
		}
	} while (iQuanly >= 1 && iQuanly <= 3);
}
/**********************************************************
* @Description Delete book
**********************************************************/
void xoaSach()
{
	string strMaSach = "";
	do
	{
		cout << "Nhap ma sach: ";
		rewind(stdin);
		getline(cin, strMaSach);
	} while (tinhTrangSach(strMaSach) == 0);
	for (int i = 0; i < S.size(); i++)
	{
		if (strMaSach == S[i].getMaSach())
		{
			S.erase(S.begin() + i);
			ghiDSSach(S);
			break;
		}
	}
	cout << "Xoa thanh cong" << endl;
}
/**********************************************************
* @Description Check book status
**********************************************************/
bool tinhTrangSach(string strMaSach)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getMaSach() == strMaSach && S[i].getTinhTrang() == 0)
		{
			return true;
		}
	}
	return false;
}
/**********************************************************
* @Description Write file Sach.txt
**********************************************************/
void ghiDSSach(vector<Sach> S)
{
	ofstream fcout;
	fcout.open("Sach.txt");
	fcout << S.size() << endl;
	for (int i = 0; i < S.size(); i++)
	{
		S[i].writeSach(fcout);
	}
	fcout.close();
}
/**********************************************************
* @Description Manage reader
**********************************************************/
void quanLyBanDoc()
{
	GiaoVien giaovien;
	SinhVien sinhvien;
	ofstream fcout;
	ifstream fcin;
	int iN = 0;
	fcin.open("SinhVien.txt");
	fcin >> iN;
	fcin.ignore(1);
	int iQuanly = 0;
	do {
		SetColor(11);
		cout << "________________QUAN LY BAN DOC______________\n";
		cout << "*********************************************\n";
		SetColor(14);
		cout << "\t 1. XEM BAN DOC GIAO VIEN \t\n";
		cout << "\t 2. XEM BAN DOC SINH VIEN \t\n";
		cout << "\t 3. THEM BAN DOC GIAO VIEN \t\n";
		cout << "\t 4. THEM BAN DOC SINH VIEN \t\n";
		cout << "\t 5. THOAT \t\n";
		SetColor(11);
		cout << "*********************************************\n";
		SetColor(14);
		cout << "Ban hay chon chuc nang can quan ly: ";
		cin >> iQuanly;
		switch (iQuanly)
		{
		case 1:
			system("cls");
			xuatDSGV(Gv);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			xuatDSSV(Sv);
			system("pause");
			system("cls");
			break;
		case 3:
			giaovien.nhapGiaoVienMoi();
			cout << "THEM GIAO VIEN THANH CONG!";
			system("pause");
			system("cls");
			break;
		case 4:
			sinhvien.nhapSinhVienMoi();
			cout << "THEM SINH VIEN THANH CONG!";
			system("pause");
			system("cls");
			break;
		default:
			cout << "BAN CHON THOAT QUAN LY BAN DOC!\n";
			Sleep(1000);
			system("cls");
			quanLyThuVien();
			break;
		}
	} while (iQuanly >= 1 && iQuanly <= 4);
}
/**********************************************************
* @Description Statistic
**********************************************************/
void thongKe() {
	int iQuanly = 0;
	do {
		system("cls");
		SetColor(11);
		cout << "__________________THONG KE_______________\n";
		cout << "*********************************************\n";
		SetColor(14);
		cout << "\t 1. TONG SACH DA MUON \t\n";
		cout << "\t 2. TONG SACH CHUA MUON \t\n";
		cout << "\t 3. THOAT \t\n";
		SetColor(11);
		cout << "*********************************************\n";
		SetColor(14);
		cout << "Ban hay chon chuc nang can quan ly: ";
		cin >> iQuanly;
		switch (iQuanly)
		{
		case 1:
			system("cls");
			tongSachMuon();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			tongSachChuaMuon();
			system("pause");
			system("cls");
			break;
		default:
			cout << "BAN CHON THOAT THONG KE!\n";
			Sleep(1000);
			system("cls");
			quanLyThuVien();
			break;
		}
	} while (iQuanly >= 1 && iQuanly <= 3);
}
/**********************************************************
* @Description Total the available book
**********************************************************/
void tongSachChuaMuon()
{
	int iTONG = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 0)
		{
			iTONG += 1;
		}
	}
	cout << "Tong so luong sach chua muon la: " << iTONG << endl << endl;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 0)
		{
			cout << S[i];
		}
	}
}
/**********************************************************
* @Description Total the borrowed book
**********************************************************/
void tongSachMuon()
{
	int iTONG = 0;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 1)
		{
			iTONG++;
		}
	}
	cout << "Tong so luong sach da muon la: " << iTONG << endl;
	for (int i = 0; i < S.size(); i++)
	{
		if (S[i].getTinhTrang() == 1)
		{
			cout << S[i];
		}
	}
}
/**********************************************************
* @Description Set color
**********************************************************/
void SetColor(int ForgC)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	//We use csbi for the wAttributes word.
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//Mask out all but the background attribute, and add in the forgournd color
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}