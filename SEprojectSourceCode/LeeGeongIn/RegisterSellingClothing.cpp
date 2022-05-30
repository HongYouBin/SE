#pragma once
#include "RegisterSellingClothing.h"
#include <string>

class RegisterSellingClothing;

// Function: RegisterSellingClothing(ProductList* ProductListPtr, ManageMember* manageMemberPtr)
// Description: RegisterSellingClothing Class�� �Ű����� ������
// Parameter: ProductList* ProductListPtr- �ý��� ��ü ��ǰ ����Ʈ ��ü�� �ּҸ� �޴� ������ �Ű�����, 
//            ManageMember* manageMemberPtr - �ý��� ��ü ȸ�� ���� ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
RegisterSellingClothing::RegisterSellingClothing(ProductList* ProductListPtr, ManageMember* manageMemberPtr)
{
	this->productListPtr = ProductListPtr;
	this->manageMemberPtr = manageMemberPtr;
	this->registerSellingClothingUIPtr = new RegisterSellingClothingUI(this);
	registerSellingClothingUIPtr->startInterface();
}


// Function: getRegisterSellingClothingUIPtr()
// Description: RegisterSellingClothingUIPtr ��������� getter function
// Parameter: None
// Return Value: RegisterSellingClothingUI*
// Author: ������
RegisterSellingClothingUI* RegisterSellingClothing::getRegisterSellingClothingUIPtr()
{
	return this->registerSellingClothingUIPtr;
}


// Function: addNewProduct(string name, string company, string price, string quentity)
// Description: �Ǹ����� ID������ �޾ƿ� �� Product�� ProductDB�� �����ϴ� ProductList�� createProduct�Լ��� ȣ��
// Parameter: string name - ��ǰ��, string company - ����ȸ���, string price - ��ǰ����, string quentity - ��������
// Return Value: void
// Author: ������
void RegisterSellingClothing::addNewProduct(string name, string company, string price, string quentity)
{
	string seller = this->manageMemberPtr->getSellerID();
	this->productListPtr->createProduct(seller, name, company, price, quentity);
}