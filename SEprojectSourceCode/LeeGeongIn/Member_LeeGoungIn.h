#pragma once

// Class : Member
// Description: ȸ�� ���� ���� Class
class Member
{
<<<<<<< HEAD
	string name;         // ȸ����
	string ID;           // ȸ�� ID
	string SSN;          // �ֹι�ȣ
	string password;     // ��й�ȣ
=======
	string name;
	string ID;
	string SSN;
	string password;
	vector<string> purchaseList;
>>>>>>> 692692f77fa93467b94b8bb76c6d7577f8b1ec02
public:
	Member(string name, string SSN, string ID, string password);
	string getID();
	Member* registerLoggedMember();
	vector<string> getPurchaseList();
};

