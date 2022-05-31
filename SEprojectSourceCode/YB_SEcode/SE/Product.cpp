#pragma once
#include "Product.h"
#include <string>
using namespace std;

// Function: Product(string seller, string name, string company, string price, string quentity)
// Description: Product Class의 매개변수 생성자
// Parameter: string seller- 판매자 ID, string name - 물품명, string company - 제조회사명, string price - 물품가격, 
//            string quentity - 남은수량
// Return Value: None
// Author: 이정인
Product::Product(string seller, string name, string company, string price, int quentity)
{
	this->seller = seller;
	this->name = name;
	this->company = company;
	this->price = price;
	this->quentity = quentity;
}

// 테스트용 함수
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
