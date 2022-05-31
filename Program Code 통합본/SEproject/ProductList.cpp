#pragma once
#include "ProductList.h"
#include <string>

class ProductList;

// Function: createProduct(string seller, string name, string company, string price, string quentity)
// Description: ���ο� Product�� ������ ProductDB�� ����.
// Parameter: string seller- �Ǹ��� ID, string name - ��ǰ��, string company - ����ȸ���, string price - ��ǰ����, 
//            string quentity - ��������
// Return Value: void
// Author: ������
void ProductList::createProduct(string seller, string name, string company, string price, int quentity)
{
	Product* newProduct = new Product(seller, name, company, price, stoi(quentity));
	productDB.push_back(*newProduct);
}
