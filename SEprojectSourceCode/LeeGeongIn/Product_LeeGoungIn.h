#pragma once

// Class : Product
// Description: ��ǰ ���� ���� Class
class Product
{
	string seller;          // �Ǹ��� ID
	string name;            // ��ǰ��
	string company;         // ��ǰ ���� ȸ���
	string price;           // ��ǰ ����
	int quentity;        // ����
	int evaluation = 0;     // ���Ÿ�����
	int numberOfEvaluation		//���Ÿ������� ������ �ο�
public:
	Product(string seller, string name, string company, string price, string quentity);
<<<<<<< HEAD
=======

	// �׽�Ʈ�� �Լ�
	void printInfo();
	string getName();
	void purchase();
	void addEvaluation(int evaluation);
	float getAverageEvaluation();
>>>>>>> 692692f77fa93467b94b8bb76c6d7577f8b1ec02
};

