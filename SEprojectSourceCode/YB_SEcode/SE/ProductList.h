#pragma once
#include "Product.h"

using namespace std;

class ProductList
{
	vector<Product> productDB;          // ���θ� ���α׷��� �����ϴ� ��ü ��ǰ ���� vector
public:
	void createProduct(string seller, string name, string company, string price, int quentity);
	Product* getProductInfo(string productName);
	void purchase(Product* productName);
	Product* saveEvaluationInfo(string productName, int evaluation);
};

