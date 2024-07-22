//ษจร่าว
#pragma once
#include <iostream>
#include "0Equipment.h"
using namespace std;

class SaoMiaoYi :public Equipment
{
public:
	SaoMiaoYi(int num, int sId, string name,int price, int starttime, int endtime);
	virtual void showInfo();
	virtual string getSortName();
};