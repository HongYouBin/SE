#pragma once
#include "RegisterSellingClothingUI.h"
#include "RegisterSellingClothing.h"
#include <iostream>
using namespace std;
#define MAX_STRING 32

class RegisterSellingClothing;
class RegisterSellingClothingUI;

// Function: RegisterSellingClothingUI(RegisterSellingClothing* registerSellingClothingPtr)
// Description: RegisterSellingClothingUI Class�� �Ű����� ������
// Parameter: RegisterSellingClothing* registerSellingClothingPtr- RegisterSellingClothing Control Class ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
RegisterSellingClothingUI::RegisterSellingClothingUI(RegisterSellingClothing* registerSellingClothingPtr)
{
	this->registerSellingClothingPtr = registerSellingClothingPtr;
}


// Function: startInterface()
// Description: RegisterSellingClothing ����� ù ���� ȭ���� ���
// Parameter: None
// Return Value: void
// Author: ������
void RegisterSellingClothingUI::startInterface()
{
	cout << "����� �Ƿ������� �Է��ϼ���." << endl;
}


// Function: registerNewProduct(FILE* in_fp, FILE* out_fp)
// Description: ����ڷκ��� ����� ��ǰ ������ �Է¹ް�, Control Class�� addNewProduct �Լ� ȣ��
//              ��ǰ ��� ���� ����� ����ڿ��� ���
// Parameter: FILE* in_fp - �Է� ���� ������, FILE* out_fp - ��� ���� ������
// Return Value: void
// Author: ������
void RegisterSellingClothingUI::registerNewProduct(FILE* in_fp, FILE* out_fp)
{
	char name[MAX_STRING], company[MAX_STRING], price[MAX_STRING], quentity[MAX_STRING];
	fscanf(in_fp, "%s %s %s %s", name, company, price, quentity);

	this->registerSellingClothingPtr->addNewProduct(name, company, price, quentity);

	fprintf(out_fp, "3.1 �Ǹ� �Ƿ� ���\n");
	fprintf(out_fp, "> %s %s %s %s\n", name, company, price, quentity);
}