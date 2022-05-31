#pragma once
class Product
{
	string seller;          // �Ǹ��� ID
	string name;            // ��ǰ��
	string company;         // ��ǰ ���� ȸ���
	string price;           // ��ǰ ����
	int quentity;        // ����
	int evaluation = 0;     // ���Ÿ�����
	int numberOfEvaluation;		//���Ÿ������� ������ �ο�
public:
	Product(string seller, string name, string company, string price, int quentity);

	// �׽�Ʈ�� �Լ�
	string getName();
	string getSeller();
	string getPrice();
	string getCompany();
	int getQuentity();
	int getEvaluationAverage();
	void purchase();
	Product addEvaluation(int evaluation);
	float getAverageEvaluation();
};

