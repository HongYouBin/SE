#pragma once
#include "ProductList.h"
#include "Product.h"
#include <string>

// Function: createProduct(string seller, string name, string company, string price, string quentity)
// Description: ���ο� Product�� ������ ProductDB�� ����.
// Parameter: string seller- �Ǹ��� ID, string name - ��ǰ��, string company - ����ȸ���, string price - ��ǰ����, 
//            string quentity - ��������
// Return Value: void
// Author: ������
void ProductList::createProduct(string seller, string name, string company, string price, string quentity)
{
	Product* newProduct = new Product(seller, name, company, price, quentity);
	productDB.push_back(*newProduct);

	//�׽�Ʈ�� �������� ��¹�
	for (int i = 0; i < productDB.size(); i++)
	{
		productDB[i].printInfo();
	}
}
