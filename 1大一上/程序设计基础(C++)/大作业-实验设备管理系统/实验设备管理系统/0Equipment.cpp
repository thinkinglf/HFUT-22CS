#include "00LabEquipmentManager.h"
#include "1WeiJi.h"
#include "2DaYinJi.h"
#include "3SaoMiaoYi.h"

LabEquipmentManager::LabEquipmentManager()
{
	ifstream ifs(FILENAME, ios::in);
	//1�ļ������ڻ�Ϊ��        
	if (!ifs.is_open())
	{
		this->m_EquNum = 0;//ȫ����ʼ��
		this->m_EquArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2�ļ����ڲ�����������
	int num = this->get_EquNum();
	this->m_EquNum = num;
	//���ٿռ�
	this->m_EquArray = new Equipment * [this->m_EquNum];
	//���ļ��е����ݴ浽������
	this->init_Equ();//��Ҫ����
	this->m_FileIsEmpty = false;
}

void LabEquipmentManager::Show_Menu()//�˵�
{
	cout << "**************************************" << endl;
	cout << "******��ӭʹ��ʵ���豸����ϵͳ********" << endl;
	cout << "***********0.�˳�����ϵͳ:************" << endl;
	cout << "***********1.����µ��豸:************" << endl;
	cout << "***********2.��ʾ�豸��Ϣ:************" << endl;
	cout << "***********3.�ж��豸״��(�Ƿ񱨷�):**" << endl;
	cout << "***********4.ɾ�������豸:************" << endl;
	cout << "***********5.�޸��豸��Ϣ:************" << endl;
	cout << "***********6.�����豸��Ϣ:************" << endl;
	cout << "***********7.���ձ������:************" << endl;
	cout << "***********8.��������ļ�:************" << endl;
	cout << "****ע��:���ϸ���Ҫ����������!!!****" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

void LabEquipmentManager::ExistSystem()//�˳�ϵͳ
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�����
}

void LabEquipmentManager::Add_Equ()//������豸
{
	cout << "ע��:1���豸�ı�Ų�����ͬ������" << endl;
	cout << "     2���豸���Ƶĸ�ʽ(�豸����+�豸���)�밴Ҫ������" << endl;
	cout << "     3���豸�Ĺ���ʱ��ͱ���ʱ���ʽ(����x)(x��1-31֮��)(����ʾx��)(����ʱ��<=��������)" << endl;	
	cout << "     ����ʱ��>��������˵���豸�Ѿ�����" << endl;

	cout << "��������Ҫ��ӵ��豸������:" << endl;

	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EquNum + addNum;//�¿ռ����=ԭ��+������
		Equipment** newSpace = new Equipment * [newSize * sizeof(Equipment)];//��ֹ���������
		if (this->m_EquArray != NULL)//�ȸ���ԭ�е����� 
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
			cout << "�������" << i + 1 << "���豸�ı��:" << endl;
			cin >> num;
			cout << "��ѡ����豸������:" << endl;
			cout << "1��΢��" << endl;
			cout << "2����ӡ��" << endl;
			cout << "3��ɨ����" << endl;
			cin >> dSelect;
			cout << "�������" << i + 1 << "���豸������:" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "���豸�ļ۸�:" << endl;
			cin >> price;
			cout << "�������" << i + 1 << "���豸�Ĺ���ʱ��:" << endl;
			cin >> starttime;
			cout << "�������" << i + 1 << "���豸�ı���ʱ��:" << endl;
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
				cout << "��������" << endl;//�˲��ֹ���δ��д  Ĭ������û������
				return;
			}
			newSpace[this->m_EquNum + i] = equipment;//���´������豸����
		}		
		delete[] this->m_EquArray;
		this->m_EquArray = newSpace;
		this->m_EquNum = newSize;
		this->m_FileIsEmpty = false;//�����豸�������ļ���Ϊ�� 
		cout << "�ɹ����" << addNum << "���豸" << endl;
		cout << "����ʵ����һ����" << newSize << "���豸!" << endl;
		this->save();//�ɹ���Ӻ󱣴����ݵ��ļ�
	}
	else//��ӵ������������0
	{
		cout << "������������" << endl;
	}
	system("pause");
	system("cls");//����  ��������󷵻��ϼ�Ŀ¼
}

void LabEquipmentManager::save()//�����ļ� 
{
	ofstream ofs(FILENAME, ios::out);
	//��ÿ���豸������д���ļ���
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

//ͳ���ļ��е��豸����
int LabEquipmentManager::get_EquNum()
{
	ifstream ifs(FILENAME, ios::in);
	int num; int sId; string name;
	int price; int starttime; int endtime;
	int sbnum = 0;//��ֹ���豸��ų�ͻ
	while (ifs >> num && ifs >> sId && ifs >> name && ifs >> price && ifs >> starttime && ifs >> endtime)
	{
		sbnum++;
	}
	return sbnum;
}

void LabEquipmentManager::init_Equ()//��ʼ���豸(���ļ��е����ݴ浽������)(�ļ����ڲ����м�¼)

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

void LabEquipmentManager::Show_Equ()//��ʾ�豸��Ϣ
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ����Ҫ��ʾ�豸��Ϣ�ķ�ʽ:" << endl;
		cout << "1��Ĭ�Ϸ�ʽ��ʾ" << endl;
		cout << "2�������豸�����������ʾ" << endl;
		int select;
		cin >> select;
		if (select==1)//Ĭ�Ϸ�ʽ��ʾ
		{
			for (int i = 0; i < this->m_EquNum;i++)
			{
				this->m_EquArray[i]->showInfo();
			}
		}
		else//�����豸������ʾ
		{
			int x = 0, y = 0, z = 0;
			cout << "΢��:" << endl;
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
				cout << "΢���ĸ���Ϊ0��" << endl;
			}
			else
			{
				cout << "΢���ĸ���Ϊ" << x << "��" << end;
			}
			cout << endl;

			cout << "��ӡ��:" << endl;
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
				cout << "��ӡ������Ϊ0��" << endl;
			}
			else
			{
				cout << "��ӡ���ĸ���Ϊ" << y << "��" << endl;
			}
			cout << endl;

			cout << "ɨ����:" << endl;
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
				cout << "ɨ���Ǹ���Ϊ0��" << endl;
			}
			else
			{
				cout << "ɨ���ǵĸ���Ϊ" << z << "��" << endl;
			}
			cout << endl;

		}
	}
	system("pause");
	system("cls");
}

int LabEquipmentManager::IsExist(int num)//�ж��豸�Ƿ����
{
	int index = -1;//�����ڷ���-1
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

void LabEquipmentManager::If_Broken()//�ж��豸�Ƿ񱨷�
{
	cout << "��������Ҫ�ж��Ƿ񱨷ϵ��豸���:" << endl;
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
			cout << "���豸��δ����" << endl;
		}
		else
		{
			cout << "���豸�Ѿ�����   ����ѡ��ɾ�����豸" << endl;
		}
	}
	else
	{
		cout << "���豸������  ����ɾ��" << endl;
	}
	system("pause");
	system("cls");
}

void LabEquipmentManager::Del_Equ()//ɾ��ָ���豸    ������ǰ�Ƶķ���
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{//�����豸�ı��ɾ���豸
		cout << "��������Ҫɾ�����豸�ı��" << endl;
		int num = 0;
		cin >> num;
		int index = this->IsExist(num);
		if (index != -1)//˵���豸���ڣ�����Ҫɾ����indexλ���ϵ��豸
		{
			for (int i = index; i < this->m_EquNum - 1; i++)//��Ϊ��1��ʼ��  
			{
				this->m_EquArray[i] = this->m_EquArray[i + 1];
			}
			this->m_EquNum--;//����ͬ������
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ����豸" << endl;
		}
	}
	system("pause");
	system("cls");
}

void LabEquipmentManager::Mod_Equ()//�޸��豸
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫ�޸ĵ��豸�ı��" << endl;
		int num;
		cin >> num;
		int ret = this->IsExist(num);
		if (ret != -1)//�豸����
		{
			delete this->m_EquArray[ret];
			int newNum = 0;
			int dSelect = 0;//�豸����
			string newName = "";//Ĭ�Ͽ��ַ���	
			int newPrice; int newStartTime; int newEndTime;
			cout << "���ҵ�:  " << num << "���豸����������ĺ���豸���" << endl;
			cin >> newNum;
			cout << "��������ĺ��豸������" << endl;
			cout << "1��΢��" << endl;
			cout << "2����ӡ��" << endl;
			cout << "3��ɨ����" << endl;
			cin >> dSelect;
			cout << "��������ĺ��豸����" << endl;
			cin >> newName;
			cout << "��������ĺ��豸�ļ۸�" << endl;
			cin >> newPrice;
			cout << "��������ĺ��豸�Ĺ���ʱ��" << endl;
			cin >> newStartTime;
			cout << "��������ĺ��豸�ı���ʱ��" << endl;
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
			//�������ݵ�������
			this->m_EquArray[ret] = equipment;
			cout << "�޸ĳɹ�!" << endl;
			//���浽�ļ�
			this->save();
		}
		else
		{
			cout << "�޸�ʧ��,�޴��豸��" << endl;
		}
	}
	system("pause");
	system("cls");
}

void LabEquipmentManager::Find_Equ()//�����豸
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "����������豸�ķ�ʽ" << endl;
		cout << "1�����豸�ı�Ų���" << endl;
		cout << "2�����豸�����Ʋ���" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{//���ձ�Ų���
			int num;
			cout << "��������Ҫ���ҵ��豸�ı��" << endl;
			cin >> num;
			int ret = IsExist(num);
			if (ret != -1)
			{
				cout << "���ҳɹ������豸��Ϣ����" << endl;
				this->m_EquArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ��,�޴��豸��" << endl;
			}
		}
		else if (select == 2)
		{//�������Ʋ���
			string name;
			cout << "��������Ҫ���ҵ��豸����" << endl;
			cin >> name;
			bool flag = false;//�ж��Ƿ�鵽�ı�־  Ĭ��δ�ҵ�
			for (int i = 0; i < m_EquNum; i++)
			{
				if (this->m_EquArray[i]->m_Name == name)
				{
					cout << "���ҳɹ������豸�ı��Ϊ:"
						<< this->m_EquArray[i]->m_Num
						<< "  ���豸����Ϣ����" << endl;
					flag = true;//ͬ�����Է�ֹ��ѭ�����ظ���ӡ����ʧ��
					//������ʾ��Ϣ�ӿ�
					this->m_EquArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ��,�޴��豸��" << endl;
			}
		}
		else
		{
			cout << "�����ѡ������" << endl;
		}
	}
	system("pause");
	system("cls");
}

void LabEquipmentManager::Sort_Equ()//ѡ������
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ" << endl;
		cout << "1�����豸�ı�Ž�������" << endl;
		cout << "2�����豸�ı�Ž��н���" << endl;
		int select;
		cin >> select;
		for (int i = 0; i < m_EquNum; i++)
		{
			int MinOrMax = i;//�������ֵ����Сֵ
			for (int j = i + 1; j < this->m_EquNum; j++)
			{
				if (select == 1)//����
				{
					if (this->m_EquArray[MinOrMax]->m_Num > this->m_EquArray[j]->m_Num)
					{
						MinOrMax = j;
					}
				}
				else//����
				{
					if (this->m_EquArray[MinOrMax]->m_Num < this->m_EquArray[j]->m_Num)
					{
						MinOrMax = j;
					}
				}
			}
			//�ж�һ��ʼ�϶������ֵ����Сֵ�ǲ������������ֵ����Сֵ   
			//�������    �ͽ�����������
			if (i != MinOrMax)
			{
				Equipment* temp = this->m_EquArray[i];
				this->m_EquArray[i] = this->m_EquArray[MinOrMax];
				this->m_EquArray[MinOrMax] = temp;
			}
		}
		this->save();//���浽�ļ�
		cout << "����ɹ��������Ľ��Ϊ:" << endl;
		for (int i = 0; i < this->m_EquNum; i++)
		{
			this->m_EquArray[i]->showInfo();
		}		
	}
	system("pause");
	system("cls");
}

void LabEquipmentManager::Clean_File()//����ļ�
{
	cout << "�Ƿ�ȷ��Ҫ��գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
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
		cout << "��ճɹ���" << endl;
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
