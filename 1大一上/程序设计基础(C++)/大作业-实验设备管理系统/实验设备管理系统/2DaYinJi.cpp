#include "2DaYinJi.h"

DaYinJi::DaYinJi(int num, int sId, string name, int price, int starttime, int endtime)
{
	this->m_Num = num;
	this->m_SortId = sId;
	this->m_Name = name;
	this->m_Price = price;
	this->m_StartTime = starttime;
	this->m_EndTime = endtime;
}
void DaYinJi::showInfo()
{
	cout << "�豸���:" << this->m_Num
		<< "  �豸����:" << this->getSortName()
		<< "  �豸����:" << this->m_Name
		<< "  �豸�۸�:" << this->m_Price
		<< "  �豸����ʱ��:" << this->m_StartTime
		<< "  �豸����ʱ��:" << this->m_EndTime
		<< endl;
}
string DaYinJi::getSortName()
{
	return string("��ӡ��");
}
