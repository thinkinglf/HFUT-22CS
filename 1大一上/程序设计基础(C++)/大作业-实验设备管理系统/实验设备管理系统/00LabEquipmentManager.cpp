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
		cout << "请输入您的选择:   " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			labequ.ExistSystem();
			break;
		case 1://增加新的设备
			labequ.Add_Equ();
			break;
		case 2://显示设备信息
			labequ.Show_Equ();
			break;
		case 3://判断设备是否报废
			labequ.If_Broken();
			break;
		case 4://删除设备
			labequ.Del_Equ();
			break;
		case 5://修改设备信息
			labequ.Mod_Equ();
			break;
		case 6://查找设备信息
			labequ.Find_Equ();
			break;
		case 7://设备排序
			labequ.Sort_Equ();
			break;
		case 8://清空文档
			labequ.Clean_File();
			break;
		default://输入错误  请重新输入
			cout << "输入有误" << endl;
			system("cls");//清屏
			break;
		}
	}
	system("pause");
	return 0;
}