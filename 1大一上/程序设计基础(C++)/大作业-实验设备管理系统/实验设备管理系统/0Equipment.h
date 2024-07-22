#pragma once//设备总称
#include <iostream>
#include <string>
using namespace std;

class Equipment
{
public:
	virtual void showInfo() = 0;       //显示设备信息
	virtual string getSortName() = 0;  //获取设备种类
	int m_Num;        //设备编号
	int m_SortId;     //设备种类编号  
	string m_Name;    //设备名称(设备种类+编号)
	int m_Price;      //设备价格
	int m_StartTime;  //购入时间
	int m_EndTime;    //报废时间
};
