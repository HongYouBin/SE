#pragma once
using namespace std;

class ProductList
{
	vector<Product> productDB;          // ���θ� ���α׷��� �����ϴ� ��ü ��ǰ ���� vector
public:
	void createProduct(string seller, string name, string company, string price, string quentity);
};

