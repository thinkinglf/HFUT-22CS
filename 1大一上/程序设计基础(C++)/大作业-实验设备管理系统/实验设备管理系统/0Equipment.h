#pragma once//�豸�ܳ�
#include <iostream>
#include <string>
using namespace std;

class Equipment
{
public:
	virtual void showInfo() = 0;       //��ʾ�豸��Ϣ
	virtual string getSortName() = 0;  //��ȡ�豸����
	int m_Num;        //�豸���
	int m_SortId;     //�豸������  
	string m_Name;    //�豸����(�豸����+���)
	int m_Price;      //�豸�۸�
	int m_StartTime;  //����ʱ��
	int m_EndTime;    //����ʱ��
};
