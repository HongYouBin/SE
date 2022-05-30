#pragma once
#include "ManageMember.h"
#include <string>
using namespace std;

// Function: getSellerID()
// Description: �Ǹ����� ID������ �޾ƿ� return�� ��
// Parameter: None
// Return Value: string
// Author: ������
string ManageMember::getSellerID()
{
	return loggedMembers[0].getID();
}


// Function: createMember(string name, string SSN, string ID, string password)
// Description: �� ȸ���� memberDB�� ����
// Parameter: string name - ȸ����, string SSN - �ֹι�ȣ, string ID - ȸ�� ID, string password - ��й�ȣ
// Return Value: void
// Author: ������
void ManageMember::createMember(string name, string SSN, string ID, string password)
{
	Member* newMember = new Member(name, SSN, ID, password);
	memberDB.push_back(*newMember);
}


// Function: checkMember(string ID, string password)
// Description: ȸ�����Ե� ����ڰ� �´��� Ȯ��
// Parameter: string ID - ȸ�� ID, string password - ��й�ȣ
// Return Value: int
// Author: ������
int ManageMember::checkMember(string ID, string password)
{
	int checkedMemberIndex = -1;
	for (int i = 0; i < memberDB.size(); i++)
	{
		if (memberDB[i].getID() == ID)
		{
			checkedMemberIndex = i;
			break;
		}
	}
	if (checkedMemberIndex < 0)
	{
		return 0;
	}
	else
	{
		Member* loginMember = memberDB[checkedMemberIndex].registerLoggedMember();
		loggedMembers.push_back(*loginMember);
		return 1;
	}
}


// Function: deleteMember()
// Description: ȸ������ ����
// Parameter: None
// Return Value: string
// Author: ������
string ManageMember::deleteMember()
{
	string deleteMemberID = loggedMembers.back().getID();
	int deleteMemberIndex = -1;
	for (int i = 0; i < memberDB.size(); i++)
	{
		if (memberDB[i].getID() == deleteMemberID)
		{
			deleteMemberIndex = i;
			break;
		}
	}
	memberDB.erase(memberDB.begin() + deleteMemberIndex);
	loggedMembers.pop_back();
	return deleteMemberID;
}


// Function: deleteLoggedMember()
// Description: �α��ε� ��� ����Ʈ���� ���� �α��� ��� ����
// Parameter: None
// Return Value: string
// Author: ������
string ManageMember::deleteLoggedMember()
{
	string logoutMemberID = loggedMembers.back().getID();
	loggedMembers.pop_back();
	return logoutMemberID;
}