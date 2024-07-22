//´òÓ¡»ú
#pragma once
#include <iostream>
#include "0Equipment.h"
using namespace std;

class DaYinJi :public Equipment
{
public:
	DaYinJi(int num, int sId, string name,int price, int starttime, int endtime);
	virtual void showInfo();
	virtual string getSortName();
};