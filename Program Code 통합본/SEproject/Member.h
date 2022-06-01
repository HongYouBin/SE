#pragma once
#include <string>
#include <vector>
using namespace std;

// Class : Member
// Description: ȸ�� ���� ���� Class
class Member
{
	string name;         // ȸ����
	string ID;           // ȸ�� ID
	string SSN;          // �ֹι�ȣ
	string password;     // ��й�ȣ
	vector<string> purchaseList;

public:
	Member(string name, string SSN, string ID, string password);
	string getID();
	Member* registerLoggedMember();
	vector<string> getPurchaseList();
	void addPurchaseList(string productName);
};

