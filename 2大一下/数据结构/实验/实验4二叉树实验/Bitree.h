#include<iostream> 
#include<string.h>
#include <stdio.h> 
using namespace std;
typedef struct BiNode {
	char data;
	struct BiNode* lChild, * rChild;
}BiNode;

//ȥ���ո�
void TrimLeft(char str[]) {
	int  i = 0;
	while (str[i] == ' ') {
		i++;
	}
	strncpy(str, str + i, 1000 - i);
}

bool ReadFileToArray(char fileName[], char strLine[100][3], int nArrLen)//��������ݴ����ά����
{   // fileName[]����ļ���
	// strLine[][3]��Ž��Ķ�ά���飬�����3�ж�Ӧ�����ļ���3��
	// nArrLen���������ĸ���
	FILE* pFile;  //������������ļ�ָ��
	char str[1000];  //��Ŷ���һ���ı����ַ���
	char strTmp[10] = "";
	pFile = fopen(fileName, "r");
	if (!pFile) {
		printf("�����������ļ���ʧ�ܣ�\n");
		return false;
	}

	while (fgets(str, 1000, pFile) != NULL)
	{
		TrimLeft(str);//���������Ϊ��ȥ������Ŀո����Զ���
		if (str[0] == '\n') {
			continue;           //��������
		}
		strncpy(strTmp, str, 2);
		if (strcmp(strTmp, "//") == 0) {
			continue;
		}
		else {
			break;
		}
	}
	if (strcmp(str, "BinaryTree\n") != 0) {
		printf("�򿪵��ļ���ʽ����\n");
		fclose(pFile);     //�ر��ļ�
		return false;
	}

	char s[10];//��ʱ�洢�����Ϣ
	while (fgets(s, 10, pFile) != NULL) {
		if (s[0] != '\n' && s[0] != '/') {
			strLine[nArrLen][0] = s[0];
			strLine[nArrLen][1] = s[3];
			strLine[nArrLen][2] = s[6];
			nArrLen++;
		}
	}
	fclose(pFile); //�ر��ļ�
	return true;
}

//����ά�������ݰ�������򴴽�������
bool CreateBiTreeFromFile(BiNode*& pBT, char strLine[100][3], int nLen, int& nRow)
{
	//strLine[100][3]--���������ݵĶ�ά����
	//nLen--������
	//nRow--���鵱ǰ�к�
	if ((nRow >= nLen) || (nLen == 0))
		return false;   //�����Ѿ�������ϣ�����û�����ݣ��˳�
	//�����������ݵݹ鴴��������
	pBT = new BiNode;  //���������            c++���
	//pBT = (BiNode*)malloc(sizeof(BiNode));   c���
	pBT->data = strLine[nRow][0];
	pBT->lChild = NULL;
	pBT->rChild = NULL;
	int nRowNext = nRow;         //�������εݹ���к�	
	if (strLine[nRowNext][1] == '1')
	{               //��ǰ�����������������һ�����ݣ��ݹ���ô�����������
		nRow++;     //�кż�1
		CreateBiTreeFromFile(pBT->lChild, strLine, nLen, nRow);
	}
	if (strLine[nRowNext][2] == '1')
	{               //��ǰ�����������������һ���������ݹ���ô�����������
		nRow++;    //�кż�1
		CreateBiTreeFromFile(pBT->rChild, strLine, nLen, nRow);
	}
	return true;
}

//���ٶ�����
void DestroyBiTree(BiNode* pBT)
{
	if (pBT)
	{
		DestroyBiTree(pBT->lChild);   //�ݹ�����������
		DestroyBiTree(pBT->rChild);   //�ݹ�����������
		delete pBT;                  //�ͷŵ�ǰ�����
	}
}

//����������������������
void outTree(BiNode* T) {
	if (T) {
		cout << T->data;
		outTree(T->lChild);
		outTree(T->rChild);
	}
}

//1
void outMidOrder(BiNode* T, int level)
{
	if (T) {
		outMidOrder(T->lChild, level + 1); //T �ĺ��Ӳ��Ϊ T �Ĳ�μ� 1
		cout << "(" << T->data << "," << level << ") "; //���ʸ����
		outMidOrder(T->rChild, level + 1); //T ���ֵܲ���� T ��ͬ
	}
}
//2
void YeAnd1Du(BiNode* T, int& Ye, int& Du) {
	if (T) {
		YeAnd1Du(T->lChild, Ye, Du);
		if (T->lChild == NULL && T->rChild == NULL) {
			Ye++;
		}
		if ((T->lChild != NULL && T->rChild == NULL) || (T->lChild == NULL && T->rChild != NULL)) {
			Du++;
		}
		YeAnd1Du(T->rChild, Ye, Du);
	}
}
//3
void find(BiNode* T, char x, bool& f) {
	if (T) {
		if (T->lChild != NULL && T->lChild->data == x) {
			cout << "x��˫�׽���ֵΪ��" << T->data << endl;
			if (T->rChild != NULL) {
				cout << "x���ֵܽ��Ϊ���ֵܣ���ֵΪ��" << T->rChild->data << endl;
			}
			if (T->lChild->lChild != NULL) {
				cout << "x�����ӽ���ֵΪ��" << T->lChild->lChild->data << endl;
			}
			else {
				cout << "û������" << endl;
			}
			if (T->lChild->rChild != NULL) {
				cout << "x���Һ��ӽ���ֵΪ��" << T->lChild->rChild->data << endl;
			}
			else {
				cout << "û���Һ���" << endl;
			}
			f = true;
			return;
		}
		else if (T->rChild != NULL && T->rChild->data == x) {
			cout << "x��˫�׽���ֵΪ��" << T->data << endl;
			if (T->lChild != NULL) {
				cout << "x���ֵܽ��Ϊ���ֵܣ���ֵΪ��" << T->lChild->data << endl;
			}
			if (T->rChild->lChild != NULL) {
				cout << "x�����ӽ���ֵΪ��" << T->rChild->lChild->data << endl;
			}
			else {
				cout << "û������" << endl;
			}
			if (T->rChild->rChild != NULL) {
				cout << "x���Һ��ӽ���ֵΪ��" << T->rChild->rChild->data << endl;
			}
			else {
				cout << "û���Һ���" << endl;
			}
			f = true;
			return;
		}
		else if (T->data == x) {
			cout << "xû��˫�׽��" << endl;
			cout << "xû���ֵܽ��" << endl;
			if (T->lChild != NULL) {
				cout << "x�����ӽ���ֵΪ��" << T->lChild->data << endl;
			}
			else {
				cout << "û������" << endl;
			}
			if (T->rChild != NULL) {
				cout << "x���Һ��ӽ���ֵΪ��" << T->rChild->data << endl;
			}
			else {
				cout << "û���Һ���" << endl;
			}
			f = true;
			return;
		}
		find(T->lChild, x, f);
		find(T->rChild, x, f);
	}
}
//4
void findH(BiNode* T, int level, char x, bool& f)
{
	if (T) {
		if (T->data == x) {
			cout << T->data << "�Ĳ��Ϊ��" << level << endl; //���ʸ����
			f = true;
		}
		findH(T->lChild, level + 1, x, f); //T �ĺ��Ӳ��Ϊ T �Ĳ�μ� 1
		findH(T->rChild, level + 1, x, f);
	}
}
//5
void ArrayToBiTree(BiNode*& T, char A[], int i, int num)
{
	//i Ϊ��ǰ����ţ��� 1 ��ʼ
	//num Ϊ�����Ч�����
	if (i <= num && A[i] != '0') {
		T = new BiNode;
		T->data = A[i];
		T->lChild = NULL;
		T->rChild = NULL;
		ArrayToBiTree(T->lChild, A, 2 * i, num);
		ArrayToBiTree(T->rChild, A, 2 * i + 1, num);
	}
}
//6
void Route(BiNode* T, char* path, int pathlen) {  //����������д�ÿ��Ҷ�ӽ�㵽������·��
	if (T) {
		if (T->lChild == NULL && T->rChild == NULL) {
			cout << "Ҷ�ӽ�� " << T->data << " ��·��Ϊ��";
			for (int i = pathlen - 1; i >= 0; i--) {
				cout << path[i] << " ";
			}
			cout << endl;
		}
		else {
			path[pathlen++] = T->data;
			Route(T->lChild, path, pathlen);
			Route(T->rChild, path, pathlen);
		}
	}
}
//7 
void LevelOrder(BiNode* T)   // �������Ĳ������
{
	BiNode* Q[100];   // ����ģ�����
	int front = 0;
	int rear = 0;
	BiNode* p;

	Q[++rear] = T;  // ��������
	while (front != rear) {   // �����в�Ϊ��
		// ��ͷ�����ӣ������ʳ��ӽ��
		p = Q[++front];
		cout << p->data << " ";
		// ���ӽ��ķǿ����Һ����������
		if (p->lChild != NULL) {
			Q[++rear] = p->lChild;
		}
		if (p->rChild != NULL) {
			Q[++rear] = p->rChild;
		}
	}
}




