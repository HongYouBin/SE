#pragma once
#include "ProductList.h"
#include "Product.h"
#include <string>
#include <vector>

// Function: createProduct(string seller, string name, string company, string price, string quentity)
// Description: ���ο� Product�� ������ ProductDB�� ����.
// Parameter: string seller- �Ǹ��� ID, string name - ��ǰ��, string company - ����ȸ���, string price - ��ǰ����, 
//            string quentity - ��������
// Return Value: void
// Author: ������
void ProductList::createProduct(string seller, string name, string company, string price, int quentity)
{
	Product* newProduct = new Product(seller, name, company, price, quentity);
	productDB.push_back(*newProduct);

	//�׽�Ʈ�� �������� ��¹�
	for (int i = 0; i < productDB.size(); i++)
	{
		productDB[i].printInfo();
	}
}

Product ProductList::getProductInfo(string productName)
{
	for (int i = 0; i < productDB.size(); ++i)
	{
		if (productDB[i].getName() == productName)
		{
			return productDB[i];
		}
	}
}

Product ProductList::purchase(string productName) 
{
	for (int i = 0; i < productDB.size(); ++i) 
	{
		if (productDB[i].getName() == productName)
		{
			productDB[i].purchase();
		}
	}
}

Product ProductList::saveEvaluationInfo(string productName, int evaluation) 
{
	for (int i = 0; i < productDB.size(); ++i)
	{
		if (productDB[i].getName() == productName)
		{
			return productDB[i].addEvaluation(evaluation);
		}
	}
}