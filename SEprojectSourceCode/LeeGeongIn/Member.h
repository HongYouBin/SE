#pragma once

// Class : Member
// Description: ȸ�� ���� ���� Class
class Member
{
	string name;         // ȸ����
	string ID;           // ȸ�� ID
	string SSN;          // �ֹι�ȣ
	string password;     // ��й�ȣ
public:
	Member(string name, string SSN, string ID, string password);
	string getID();
	Member* registerLoggedMember();
};

