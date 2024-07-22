#include "00LabEquipmentManager.h"
#include "1WeiJi.h"
#include "2DaYinJi.h"
#include "3SaoMiaoYi.h"

LabEquipmentManager::LabEquipmentManager()
{
	ifstream ifs(FILENAME, ios::in);
	//1文件不存在或为空        
	if (!ifs.is_open())
	{
		this->m_EquNum = 0;//全部初始化
		this->m_EquArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2文件存在并保存有数据
	int num = this->get_EquNum();
	this->m_EquNum = num;
	//开辟空间
	this->m_EquArray = new Equipment * [this->m_EquNum];
	//将文件中的数据存到数组中
	this->init_Equ();//重要步骤
	this->m_FileIsEmpty = false;
}

void LabEquipmentManager::Show_Menu()//菜单
{
	cout << "**************************************" << endl;
	cout << "******欢迎使用实验设备管理系统********" << endl;
	cout << "***********0.退出管理系统:************" << endl;
	cout << "***********1.添加新的设备:************" << endl;
	cout << "***********2.显示设备信息:************" << endl;
	cout << "***********3.判断设备状况(是否报废):**" << endl;
	cout << "***********4.删除报废设备:************" << endl;
	cout << "***********5.修改设备信息:************" << endl;
	cout << "***********6.查找设备信息:************" << endl;
	cout << "***********7.按照编号排序:************" << endl;
	cout << "***********8.清空所有文件:************" << endl;
	cout << "****注意:请严格按照要求输入数据!!!****" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

void LabEquipmentManager::ExistSystem()//退出系统
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出程序
}

void LabEquipmentManager::Add_Equ()//添加新设备
{
	cout << "注意:1、设备的编号不能相同！！！" << endl;
	cout << "     2、设备名称的格式(设备种类+设备编号)请按要求输入" << endl;
	cout << "     3、设备的购入时间和报废时间格式(整数x)(x在1-31之间)(即表示x号)(购入时间<=报废数据)" << endl;	
	cout << "     购入时间>报废数据说明设备已经报废" << endl;

	cout << "请输入想要添加的设备的数量:" << endl;

	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EquNum + addNum;//新空间个数=原来+新增的
		Equipment** newSpace = new Equipment * [newSize * sizeof(Equipment)];//防止缓冲区溢出
		if (this->m_EquArray != NULL)//先复制原有的数据 
		{
			for (int i = 0; i < this->m_EquNum; i++)
			{
				newSpace[i] = this->m_EquArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int num; string name; int dSelect;
			int price; int starttime; int endtime;
			cout << "请输入第" << i + 1 << "个设备的编号:" << endl;
			cin >> num;
			cout << "请选择该设备的种类:" << endl;
			cout << "1、微机" << endl;
			cout << "2、打印机" << endl;
			cout << "3、扫描仪" << endl;
			cin >> dSelect;
			cout << "请输入第" << i + 1 << "个设备的名称:" << endl;
			cin >> name;
			cout << "请输入第" << i + 1 << "个设备的价格:" << endl;
			cin >> price;
			cout << "请输入第" << i + 1 << "个设备的购入时间:" << endl;
			cin >> starttime;
			cout << "请输入第" << i + 1 << "个设备的报废时间:" << endl;
			cin >> endtime;
			Equipment* equipment = NULL;
			switch (dSelect)
			{
			case 1:
				equipment = new WeiJi(num, 1, name, price, starttime, endtime);
				break;
			case 2:
				equipment = new DaYinJi(num, 2, name, price, starttime, endtime);
				break;
			case 3:
				equipment = new SaoMiaoYi(num, 3, name, price, starttime, endtime);
				break;
			default:
				cout << "输入有误" << endl;//此部分功能未编写  默认输入没有问题
				return;
			}
			newSpace[this->m_EquNum + i] = equipment;//将新创建的设备保存
		}		
		delete[] this->m_EquArray;
		this->m_EquArray = newSpace;
		this->m_EquNum = newSize;
		this->m_FileIsEmpty = false;//更新设备数量后文件不为空 
		cout << "成功添加" << addNum << "个设备" << endl;
		cout << "现在实验室一共有" << newSize << "个设备!" << endl;
		this->save();//成功添加后保存数据到文件
	}
	else//添加的数量必须大于0
	{
		cout << "输入数据有误" << endl;
	}
	system("pause");
	system("cls");//清屏  按任意键后返回上级目录
}

void LabEquipmentManager::save()//保存文件 
{
	ofstream ofs(FILENAME, ios::out);
	//将每个设备的数据写到文件中
	for (int i = 0; i < this->m_EquNum; i++)
	{
		ofs << this->m_EquArray[i]->m_Num << "  "
			<< this->m_EquArray[i]->m_SortId << "  "
			<< this->m_EquArray[i]->m_Name << "  "
			<< this->m_EquArray[i]->m_Price << "  "
			<< this->m_EquArray[i]->m_StartTime << "  "
			<< this->m_EquArray[i]->m_EndTime << "  "
			<< endl;
	}
	ofs.close();
}

//统计文件中的设备个数
int LabEquipmentManager::get_EquNum()
{
	ifstream ifs(FILENAME, ios::in);
	int num; int sId; string name;
	int price; int starttime; int endtime;
	int sbnum = 0;//防止与设备编号冲突
	while (ifs >> num && ifs >> sId && ifs >> name && ifs >> price && ifs >> starttime && ifs >> endtime)
	{
		sbnum++;
	}
	return sbnum;
}

void LabEquipmentManager::init_Equ()//初始化设备(把文件中的数据存到数组中)(文件存在并且有记录)

{
	ifstream ifs(FILENAME, ios::in);
	int num; int sId; string name;
	int price; int starttime; int endtime;
	int index = 0;
	while (ifs >> num && ifs >> sId && ifs >> name && ifs >> price && ifs >> starttime && ifs >> endtime)
	{
		Equipment* equipment = NULL;
		if (sId == 1)
		{
			equipment = new WeiJi(num, sId, name, price, starttime, endtime);
		}
		else if (sId == 2)
		{
			equipment = new DaYinJi(num, sId, name, price, starttime, endtime);
		}
		else
		{
			equipment = new SaoMiaoYi(num, sId, name, price, starttime, endtime);
		}
		this->m_EquArray[index] = equipment;
		index++;
	}
	ifs.close();
}

void LabEquipmentManager::Show_Equ()//显示设备信息
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择想要显示设备信息的方式:" << endl;
		cout << "1、默认方式显示" << endl;
		cout << "2、按照设备的种类进行显示" << endl;
		int select;
		cin >> select;
		if (select==1)//默认方式显示
		{
			for (int i = 0; i < this->m_EquNum;i++)
			{
				this->m_EquArray[i]->showInfo();
			}
		}
		else//按照设备种类显示
		{
			int x = 0, y = 0, z = 0;
			cout << "微机:" << endl;
			for (int i = 0; i < this->m_EquNum; i++)
			{
				if(this->m_EquArray[i]->m_SortId==1)
				{
					this->m_EquArray[i]->showInfo();
					x++;
				}
			}
			if (x == 0)
			{
				cout << "微机的个数为0个" << endl;
			}
			else
			{
				cout << "微机的个数为" << x << "个" << end;
			}
			cout << endl;

			cout << "打印机:" << endl;
			for (int i = 0; i < this->m_EquNum; i++)
			{
				if (this->m_EquArray[i]->m_SortId == 2)
				{
					this->m_EquArray[i]->showInfo();
					y++;
				}
			}
			if (y == 0)
			{
				cout << "打印机个数为0个" << endl;
			}
			else
			{
				cout << "打印机的个数为" << y << "个" << endl;
			}
			cout << endl;

			cout << "扫描仪:" << endl;
			for (int i = 0; i < this->m_EquNum; i++)
			{
				if (this->m_EquArray[i]->m_SortId == 3)
				{
					this->m_EquArray[i]->showInfo();
					z++;
				}
			}
			if (z == 0)
			{
				cout << "扫描仪个数为0个" << endl;
			}
			else
			{
				cout << "扫描仪的个数为" << z << "个" << endl;
			}
			cout << endl;

		}
	}
	system("pause");
	system("cls");
}

int LabEquipmentManager::IsExist(int num)//判断设备是否存在
{
	int index = -1;//不存在返回-1
	for (int i = 0; i < this->m_EquNum; i++)
	{
		if (this->m_EquArray[i]->m_Num == num)
		{
			index = i;
			break;
		}
	}
	return index;
}

void LabEquipmentManager::If_Broken()//判断设备是否报废
{
	cout << "请输入想要判断是否报废的设备编号:" << endl;
	int selectNum;
	cin >> selectNum;

	int temp = IsExist(selectNum);

	int i = 0;
	if (temp != -1)
	{
		for (; i < get_EquNum(); i++)
		{
			if (m_EquArray[i]->m_Num == selectNum)
				break;
		}
		if (this->m_EquArray[i]->m_StartTime <= this->m_EquArray[i]->m_EndTime)
		{
			cout << "该设备还未报废" << endl;
		}
		else
		{
			cout << "该设备已经报废   可以选择删除该设备" << endl;
		}
	}
	else
	{
		cout << "该设备不存在  无需删除" << endl;
	}
	system("pause");
	system("cls");
}

void LabEquipmentManager::Del_Equ()//删除指定设备    用数据前移的方法
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{//按照设备的编号删除设备
		cout << "请输入想要删除的设备的编号" << endl;
		int num = 0;
		cin >> num;
		int index = this->IsExist(num);
		if (index != -1)//说明设备存在，并且要删除掉index位置上的设备
		{
			for (int i = index; i < this->m_EquNum - 1; i++)//因为从1开始加  
			{
				this->m_EquArray[i] = this->m_EquArray[i + 1];
			}
			this->m_EquNum--;//数据同步更新
			this->save();
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该设备" << endl;
		}
	}
	system("pause");
	system("cls");
}

void LabEquipmentManager::Mod_Equ()//修改设备
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入想要修改的设备的编号" << endl;
		int num;
		cin >> num;
		int ret = this->IsExist(num);
		if (ret != -1)//设备存在
		{
			delete this->m_EquArray[ret];
			int newNum = 0;
			int dSelect = 0;//设备种类
			string newName = "";//默认空字符串	
			int newPrice; int newStartTime; int newEndTime;
			cout << "查找到:  " << num << "号设备，请输入更改后的设备编号" << endl;
			cin >> newNum;
			cout << "请输入更改后设备的种类" << endl;
			cout << "1、微机" << endl;
			cout << "2、打印机" << endl;
			cout << "3、扫描仪" << endl;
			cin >> dSelect;
			cout << "请输入更改后设备名称" << endl;
			cin >> newName;
			cout << "请输入更改后设备的价格" << endl;
			cin >> newPrice;
			cout << "请输入更改后设备的购入时间" << endl;
			cin >> newStartTime;
			cout << "请输入更改后设备的报废时间" << endl;
			cin >> newEndTime;
			Equipment* equipment = NULL;
			switch (dSelect)
			{
			case 1:
				equipment = new WeiJi(newNum, dSelect, newName, newPrice, newStartTime, newEndTime);
				break;
			case 2:
				equipment = new DaYinJi(newNum, dSelect, newName, newPrice, newStartTime, newEndTime);
				break;
			case 3:
				equipment = new SaoMiaoYi(newNum, dSelect, newName, newPrice, newStartTime, newEndTime);
				break;
			default:
				break;
			}
			//更新数据到数组中
			this->m_EquArray[ret] = equipment;
			cout << "修改成功!" << endl;
			//保存到文件
			this->save();
		}
		else
		{
			cout << "修改失败,无此设备！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void LabEquipmentManager::Find_Equ()//查找设备
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找设备的方式" << endl;
		cout << "1、按设备的编号查找" << endl;
		cout << "2、按设备的名称查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{//按照编号查找
			int num;
			cout << "请输入想要查找的设备的编号" << endl;
			cin >> num;
			int ret = IsExist(num);
			if (ret != -1)
			{
				cout << "查找成功！该设备信息如下" << endl;
				this->m_EquArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败,无此设备！" << endl;
			}
		}
		else if (select == 2)
		{//按照名称查找
			string name;
			cout << "请输入想要查找的设备名称" << endl;
			cin >> name;
			bool flag = false;//判断是否查到的标志  默认未找到
			for (int i = 0; i < m_EquNum; i++)
			{
				if (this->m_EquArray[i]->m_Name == name)
				{
					cout << "查找成功！该设备的编号为:"
						<< this->m_EquArray[i]->m_Num
						<< "  该设备的信息如下" << endl;
					flag = true;//同样可以防止在循环内重复打印查找失败
					//调用显示信息接口
					this->m_EquArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败,无此设备！" << endl;
			}
		}
		else
		{
			cout << "输入的选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

void LabEquipmentManager::Sort_Equ()//选择排序
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1、按设备的编号进行升序" << endl;
		cout << "2、按设备的编号进行降序" << endl;
		int select;
		cin >> select;
		for (int i = 0; i < m_EquNum; i++)
		{
			int MinOrMax = i;//声明最大值或最小值
			for (int j = i + 1; j < this->m_EquNum; j++)
			{
				if (select == 1)//升序
				{
					if (this->m_EquArray[MinOrMax]->m_Num > this->m_EquArray[j]->m_Num)
					{
						MinOrMax = j;
					}
				}
				else//降序
				{
					if (this->m_EquArray[MinOrMax]->m_Num < this->m_EquArray[j]->m_Num)
					{
						MinOrMax = j;
					}
				}
			}
			//判读一开始认定的最大值或最小值是不是排序后的最大值或最小值   
			//如果不是    就交换这两个数
			if (i != MinOrMax)
			{
				Equipment* temp = this->m_EquArray[i];
				this->m_EquArray[i] = this->m_EquArray[MinOrMax];
				this->m_EquArray[MinOrMax] = temp;
			}
		}
		this->save();//保存到文件
		cout << "排序成功！排序后的结果为:" << endl;
		for (int i = 0; i < this->m_EquNum; i++)
		{
			this->m_EquArray[i]->showInfo();
		}		
	}
	system("pause");
	system("cls");
}

void LabEquipmentManager::Clean_File()//清空文件
{
	cout << "是否确认要清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EquArray != NULL)
		{
			for (int i = 0; i < this->m_EquNum; i++)
			{
				delete this->m_EquArray[i];
				this->m_EquArray[i] = NULL;
			}
			delete[] this->m_EquArray;
			this->m_EquArray = NULL;
			this->m_EquNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}

LabEquipmentManager::~LabEquipmentManager()
{
	if (this->m_EquArray != NULL)
	{
		for (int i = 0; i < this->m_EquNum; i++)
		{
			if (this->m_EquArray[i] != NULL)
			{
				delete this->m_EquArray[i];
				m_EquArray[i] = NULL;
			}
		}
		delete[] this->m_EquArray;
		this->m_EquArray = NULL;
	}
}
