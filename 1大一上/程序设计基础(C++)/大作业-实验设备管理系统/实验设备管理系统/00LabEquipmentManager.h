#pragma once//��ֹһ��ͷ�ļ����ظ�����
#include <iostream>
#include "0Equipment.h"
#include "1WeiJi.h"
#include "2DaYinJi.h"
#include "3SaoMiaoYi.h"

#include <fstream>
#define FILENAME "equFile.txt"//�곣�������ļ���(���ں�������)

using namespace std;
class LabEquipmentManager
{
public:
	LabEquipmentManager();
	void Show_Menu();//չʾ�˵�
	void ExistSystem();//�˳�ϵͳ

	int m_EquNum;//�豸����
	Equipment** m_EquArray;//�豸�����ָ��

	void Add_Equ();//����豸 
	void save();//�����ļ�
	bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��  
	int get_EquNum();//ͳ���ļ����豸����
	void init_Equ();//��ʼ���豸
	void Show_Equ();//��ʾ�豸��Ϣ
	void If_Broken();//�ж��豸�Ƿ񱨷�
	void Del_Equ();//ɾ��ָ���豸
	void Mod_Equ();//�޸��豸��Ϣ
	void Find_Equ();//�����豸��Ϣ
	int IsExist(int id);//�ж��豸�Ƿ���� ������ڷ����豸�����豸�����λ�ã������ڷ���-1
	void Sort_Equ();//���ձ������
	void Clean_File();//����ļ�
	~LabEquipmentManager();
};