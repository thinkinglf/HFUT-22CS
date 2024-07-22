#include<iostream> 
#include<string.h>
#include <stdio.h> 
using namespace std;
typedef struct BiNode {
	char data;
	struct BiNode* lChild, * rChild;
}BiNode;

//去除空格
void TrimLeft(char str[]) {
	int  i = 0;
	while (str[i] == ' ') {
		i++;
	}
	strncpy(str, str + i, 1000 - i);
}

bool ReadFileToArray(char fileName[], char strLine[100][3], int nArrLen)//将结点数据存入二维数组
{   // fileName[]存放文件名
	// strLine[][3]存放结点的二维数组，数组的3列对应数据文件的3列
	// nArrLen二叉树结点的个数
	FILE* pFile;  //定义二叉树的文件指针
	char str[1000];  //存放读出一行文本的字符串
	char strTmp[10] = "";
	pFile = fopen(fileName, "r");
	if (!pFile) {
		printf("二叉树数据文件打开失败！\n");
		return false;
	}

	while (fgets(str, 1000, pFile) != NULL)
	{
		TrimLeft(str);//这个函数是为了去掉左面的空格，须自定义
		if (str[0] == '\n') {
			continue;           //空行跳过
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
		printf("打开的文件格式错误！\n");
		fclose(pFile);     //关闭文件
		return false;
	}

	char s[10];//临时存储结点信息
	while (fgets(s, 10, pFile) != NULL) {
		if (s[0] != '\n' && s[0] != '/') {
			strLine[nArrLen][0] = s[0];
			strLine[nArrLen][1] = s[3];
			strLine[nArrLen][2] = s[6];
			nArrLen++;
		}
	}
	fclose(pFile); //关闭文件
	return true;
}

//将二维数组数据按先序次序创建二叉树
bool CreateBiTreeFromFile(BiNode*& pBT, char strLine[100][3], int nLen, int& nRow)
{
	//strLine[100][3]--保存结点数据的二维数组
	//nLen--结点个数
	//nRow--数组当前行号
	if ((nRow >= nLen) || (nLen == 0))
		return false;   //数据已经处理完毕，或者没有数据，退出
	//根据数组数据递归创建二叉树
	pBT = new BiNode;  //建立根结点            c++风格
	//pBT = (BiNode*)malloc(sizeof(BiNode));   c风格
	pBT->data = strLine[nRow][0];
	pBT->lChild = NULL;
	pBT->rChild = NULL;
	int nRowNext = nRow;         //保留本次递归的行号	
	if (strLine[nRowNext][1] == '1')
	{               //当前结点有左子树，读下一行数据，递归调用创建左子树。
		nRow++;     //行号加1
		CreateBiTreeFromFile(pBT->lChild, strLine, nLen, nRow);
	}
	if (strLine[nRowNext][2] == '1')
	{               //当前结点有右子树，读下一行数数，递归调用创建右子树。
		nRow++;    //行号加1
		CreateBiTreeFromFile(pBT->rChild, strLine, nLen, nRow);
	}
	return true;
}

//销毁二叉树
void DestroyBiTree(BiNode* pBT)
{
	if (pBT)
	{
		DestroyBiTree(pBT->lChild);   //递归销毁左子树
		DestroyBiTree(pBT->rChild);   //递归销毁右子树
		delete pBT;                  //释放当前根结点
	}
}

//先序遍历输出二叉树的数据
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
		outMidOrder(T->lChild, level + 1); //T 的孩子层次为 T 的层次加 1
		cout << "(" << T->data << "," << level << ") "; //访问根结点
		outMidOrder(T->rChild, level + 1); //T 的兄弟层次与 T 相同
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
			cout << "x的双亲结点的值为：" << T->data << endl;
			if (T->rChild != NULL) {
				cout << "x的兄弟结点为右兄弟，其值为：" << T->rChild->data << endl;
			}
			if (T->lChild->lChild != NULL) {
				cout << "x的左孩子结点的值为：" << T->lChild->lChild->data << endl;
			}
			else {
				cout << "没有左孩子" << endl;
			}
			if (T->lChild->rChild != NULL) {
				cout << "x的右孩子结点的值为：" << T->lChild->rChild->data << endl;
			}
			else {
				cout << "没有右孩子" << endl;
			}
			f = true;
			return;
		}
		else if (T->rChild != NULL && T->rChild->data == x) {
			cout << "x的双亲结点的值为：" << T->data << endl;
			if (T->lChild != NULL) {
				cout << "x的兄弟结点为左兄弟，其值为：" << T->lChild->data << endl;
			}
			if (T->rChild->lChild != NULL) {
				cout << "x的左孩子结点的值为：" << T->rChild->lChild->data << endl;
			}
			else {
				cout << "没有左孩子" << endl;
			}
			if (T->rChild->rChild != NULL) {
				cout << "x的右孩子结点的值为：" << T->rChild->rChild->data << endl;
			}
			else {
				cout << "没有右孩子" << endl;
			}
			f = true;
			return;
		}
		else if (T->data == x) {
			cout << "x没有双亲结点" << endl;
			cout << "x没有兄弟结点" << endl;
			if (T->lChild != NULL) {
				cout << "x的左孩子结点的值为：" << T->lChild->data << endl;
			}
			else {
				cout << "没有左孩子" << endl;
			}
			if (T->rChild != NULL) {
				cout << "x的右孩子结点的值为：" << T->rChild->data << endl;
			}
			else {
				cout << "没有右孩子" << endl;
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
			cout << T->data << "的层次为：" << level << endl; //访问根结点
			f = true;
		}
		findH(T->lChild, level + 1, x, f); //T 的孩子层次为 T 的层次加 1
		findH(T->rChild, level + 1, x, f);
	}
}
//5
void ArrayToBiTree(BiNode*& T, char A[], int i, int num)
{
	//i 为当前结点编号，从 1 开始
	//num 为最后有效结点编号
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
void Route(BiNode* T, char* path, int pathlen) {  //输出二叉树中从每个叶子结点到根结点的路径
	if (T) {
		if (T->lChild == NULL && T->rChild == NULL) {
			cout << "叶子结点 " << T->data << " 的路径为：";
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
void LevelOrder(BiNode* T)   // 二叉树的层序遍历
{
	BiNode* Q[100];   // 数组模拟队列
	int front = 0;
	int rear = 0;
	BiNode* p;

	Q[++rear] = T;  // 根结点入队
	while (front != rear) {   // 若队列不为空
		// 队头结点出队，并访问出队结点
		p = Q[++front];
		cout << p->data << " ";
		// 出队结点的非空左右孩子依次入队
		if (p->lChild != NULL) {
			Q[++rear] = p->lChild;
		}
		if (p->rChild != NULL) {
			Q[++rear] = p->rChild;
		}
	}
}




