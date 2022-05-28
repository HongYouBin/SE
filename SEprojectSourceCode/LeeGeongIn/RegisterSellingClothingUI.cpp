#pragma once
#include "RegisterSellingClothingUI.h"
#include "RegisterSellingClothing.h"
#include <iostream>
#define MAX_STRING 32

RegisterSellingClothingUI::RegisterSellingClothingUI(RegisterSellingClothing* registerSellingClothingPtr)
{
	this->registerSellingClothingPtr = registerSellingClothingPtr;
}

void RegisterSellingClothingUI::startInterface()
{
	cout << "����� �Ƿ������� �Է��ϼ���." << endl;
}

void RegisterSellingClothingUI::registerNewProduct(FILE* in_fp, FILE* out_fp)
{
	char name[MAX_STRING], company[MAX_STRING], price[MAX_STRING], quentity[MAX_STRING];
	fscanf(in_fp, "%s %s %s %s", name, company, price, quentity);

	this->registerSellingClothingPtr->addNewProduct(name, company, price, quentity);

	fprintf(out_fp, "3.1 �Ǹ� �Ƿ� ���\n");
	fprintf(out_fp, "> [%s] [%s] [%s] [%s]\n", name, company, price, quentity);
}
