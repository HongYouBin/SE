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
Product::Product(string seller, string name, string company, string price, int quentity)
{
	this->seller = seller;
	this->name = name;
	this->company = company;
	this->price = price;
	this->quentity = quentity;
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

Product Product::addEvaluation(int evaluation)
{
	this->evaluation += evaluation;
	this->numberOfEvaluation++;
	return *this;
}

float Product::getAverageEvaluation()
{
	return this->evaluation / this->numberOfEvaluation;
}