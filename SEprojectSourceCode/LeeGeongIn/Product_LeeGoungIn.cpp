#pragma once
#include "Product.h"
#include <string>
using namespace std;

// Function: Product(string seller, string name, string company, string price, string quentity)
// Description: Product Class�� �Ű����� ������
// Parameter: string seller- �Ǹ��� ID, string name - ��ǰ��, string company - ����ȸ���, string price - ��ǰ����, 
//            string quentity - ��������
// Return Value: None
// Author: ������
Product::Product(string seller, string name, string company, string price, string quentity)
{
	this->seller = seller;
	this->name = name;
	this->company = company;
	this->price = price;
	this->quentity = quentity;
<<<<<<< HEAD
}
=======
}

// �׽�Ʈ�� �Լ�
/*void Product::printInfo()
{
	cout << this->seller << " " << this->name << " " << this->company << " " << this->price << " " << this->quentity << endl;
}*/

string Product::getName()
{
	return this->name;
}

void Product::purchase() 
{
	this->quentity--;
}

void Product::addEvaluation(int evaluation)
{
	this->evaluation += evaluation;
	this->numberOfEvaluation++;
}

float Product::getAverageEvaluation()
{
	return this->evaluation / this->numberOfEvaluation;
}
>>>>>>> 692692f77fa93467b94b8bb76c6d7577f8b1ec02