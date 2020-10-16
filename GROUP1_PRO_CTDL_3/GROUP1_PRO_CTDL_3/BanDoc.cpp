#include "BANDOC.h"

string BanDoc::getHovaten()
{
	return this->_strHoTen;
}
string BanDoc::getKhoa()
{
	return this->_strKhoa;
}
string BanDoc::getMaBanDoc()
{
	return this->_strMaBanDoc;
}
void BanDoc::setHovaten(string strHoTen)
{
	this->_strHoTen = strHoTen;
}
void BanDoc::setKhoa(string strKhoa)
{
	this->_strKhoa = strKhoa;
}
void BanDoc::setMaBanDoc(string strMaBanDoc)
{
	this->_strMaBanDoc = strMaBanDoc;
}
void BanDoc::setBandoc(string strHoTen, string strKhoa, string strMaBanDoc)
{
	this->_strHoTen = strHoTen;
	this->_strKhoa = strKhoa;
	this->_strMaBanDoc = strMaBanDoc;
}