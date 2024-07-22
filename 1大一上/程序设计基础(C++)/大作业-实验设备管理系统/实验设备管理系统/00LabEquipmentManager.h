#pragma once//防止一个头文件被重复包含
#include <iostream>
#include "0Equipment.h"
#include "1WeiJi.h"
#include "2DaYinJi.h"
#include "3SaoMiaoYi.h"

#include <fstream>
#define FILENAME "equFile.txt"//宏常量定义文件名(便于后续操作)

using namespace std;
class LabEquipmentManager
{
public:
	LabEquipmentManager();
	void Show_Menu();//展示菜单
	void ExistSystem();//退出系统

	int m_EquNum;//设备数量
	Equipment** m_EquArray;//设备数组的指针

	void Add_Equ();//添加设备 
	void save();//保存文件
	bool m_FileIsEmpty;//判断文件是否为空  
	int get_EquNum();//统计文件中设备数量
	void init_Equ();//初始化设备
	void Show_Equ();//显示设备信息
	void If_Broken();//判断设备是否报废
	void Del_Equ();//删除指定设备
	void Mod_Equ();//修改设备信息
	void Find_Equ();//查找设备信息
	int IsExist(int id);//判断设备是否存在 如果存在返回设备其在设备数组的位置，不存在返回-1
	void Sort_Equ();//按照编号排序
	void Clean_File();//清空文件
	~LabEquipmentManager();
};