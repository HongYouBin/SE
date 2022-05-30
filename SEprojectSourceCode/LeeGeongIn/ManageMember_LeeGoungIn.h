#pragma once
#include <vector>
#include "Member.h"

class Member;

// Class : ManageMember
// Description: �ý��� �� ȸ�� ����Ʈ ���� �� �α��� ȸ�� ���� ����, ȸ�� ���� Ȯ���� ���� Class
class ManageMember
{
	vector<Member> memberDB;          // ���θ� ���α׷��� �����ϴ� ��ü ȸ�� ���� vector
	vector<Member> loggedMembers;     // ���� ���θ� ���α׷��� �α����� ȸ�� ���� vector
public:
	string getSellerID();
	void createMember(string name, string SSN, string ID, string password);
	int checkMember(string ID, string password);
	string deleteMember();
	string deleteLoggedMember();
	void addPurchaseList(string productName);
	string getPurchaseList();
};
