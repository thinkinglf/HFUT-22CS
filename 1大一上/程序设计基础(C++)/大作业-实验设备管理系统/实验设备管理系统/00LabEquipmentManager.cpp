#include <iostream>
#include "00LabEquipmentManager.h"
#include "0Equipment.h"
#include "1Weiji.h"
#include "2DaYinJi.h"
#include "3SaoMiaoYi.h"

using namespace std;
int main()
{
	LabEquipmentManager labequ;
	int choice = 0;
	while (true)
	{
		labequ.Show_Menu();
		cout << "����������ѡ��:   " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			labequ.ExistSystem();
			break;
		case 1://�����µ��豸
			labequ.Add_Equ();
			break;
		case 2://��ʾ�豸��Ϣ
			labequ.Show_Equ();
			break;
		case 3://�ж��豸�Ƿ񱨷�
			labequ.If_Broken();
			break;
		case 4://ɾ���豸
			labequ.Del_Equ();
			break;
		case 5://�޸��豸��Ϣ
			labequ.Mod_Equ();
			break;
		case 6://�����豸��Ϣ
			labequ.Find_Equ();
			break;
		case 7://�豸����
			labequ.Sort_Equ();
			break;
		case 8://����ĵ�
			labequ.Clean_File();
			break;
		default://�������  ����������
			cout << "��������" << endl;
			system("cls");//����
			break;
		}
	}
	system("pause");
	return 0;
}