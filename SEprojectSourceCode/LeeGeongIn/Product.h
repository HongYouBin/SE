#pragma once
class Product
{
	string seller;          // �Ǹ��� ID
	string name;            // ��ǰ��
	string company;         // ��ǰ ���� ȸ���
	string price;           // ��ǰ ����
	string quentity;        // ����
	int evaluation = 0;     // ���Ÿ�����
public:
	Product(string seller, string name, string company, string price, string quentity);

	// �׽�Ʈ�� �Լ�
	void printInfo();
};

