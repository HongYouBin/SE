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
void ProductList::createProduct(string seller, string name, string company, string price, string quentity)
{
	Product* newProduct = new Product(seller, name, company, price, quentity);
	productDB.push_back(*newProduct);
}

Product ProductList::getProductInfo(string productName)
{
	for (int i = 0; i < productDB.size(); ++i)
	{
		if (productDB[i].getName == productName)
		{
			return productDB[i];
		}
	}
}

Product ProductList::purchase(string productName) 
{
	for (int i = 0; i < productDB.size(); ++i) 
	{
		if (productDB[i].getName == productName)
		{
			productDB[i].purchase();
		}
	}
}

void Product::saveEvaluationInfo(string productName, int evaluation) 
{
	for (int i = 0; i < productDB.size(); ++i)
	{
		if (productDB[i].getName == productName)
		{
			productDB[i].addEvaluation;
		}
	}
}
