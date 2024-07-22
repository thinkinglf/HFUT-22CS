#include "3SaoMiaoYi.h"

SaoMiaoYi::SaoMiaoYi(int num, int sId, string name, int price, int starttime, int endtime)
{
	this->m_Num = num;
	this->m_SortId = sId;
	this->m_Name = name;
	this->m_Price = price;
	this->m_StartTime = starttime;
	this->m_EndTime = endtime;
}
void SaoMiaoYi::showInfo()
{
	cout << "设备编号:" << this->m_Num
		<< "  设备种类:" << this->getSortName()
		<< "  设备名称:" << this->m_Name
		<< "  设备价格:" << this->m_Price
		<< "  设备购入时间:" << this->m_StartTime
		<< "  设备报废时间:" << this->m_EndTime
		<< endl;
}
string SaoMiaoYi::getSortName()
{
	return string("扫描仪");
}
