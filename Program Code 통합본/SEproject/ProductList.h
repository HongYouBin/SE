#pragma once
#include "Product.h"

class Product;

// Class : ProductList
// Description: �ý��� �� ��ǰ ����Ʈ ���� Class
class ProductList
{
	vector<Product> productDB;          // ���θ� ���α׷��� �����ϴ� ��ü ��ǰ ���� vector
public:
	void createProduct(string seller, string name, string company, string price, int quentity);
	Product* getProductInfo(string productName);
	void purchase(Product* productName);
	Product* saveEvaluationInfo(string productName, int evaluation);
};
