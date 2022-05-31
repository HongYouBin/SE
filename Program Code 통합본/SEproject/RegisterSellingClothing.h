#pragma once
#include "RegisterSellingClothingUI.h"
#include "ProductList.h"
#include "ManageMember.h"
using namespace std;

class RegisterSellingClothingUI;
class ManageMember;
class Product;

// Class : RegisterSellingClothing
// Description: �Ǹ� ��ǰ ��� ����� Control Class
class RegisterSellingClothing
{
	RegisterSellingClothingUI* registerSellingClothingUIPtr;   // RegisterSellingClothing ����� boundary class pointer
	ProductList* productListPtr;                               // systemProductDB ��ü�� �ּҸ� �����ϴ� pointer
	ManageMember* manageMemberPtr;                             // systemMemberDB ��ü�� �ּҸ� �����ϴ� pointer
public:
	RegisterSellingClothing(ProductList* productListPtr, ManageMember* manageMemberPtr);
	RegisterSellingClothingUI* getRegisterSellingClothingUIPtr();
	void addNewProduct(string name, string company, string price, string quentity);
};

