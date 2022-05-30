#pragma once
#include "JoinMembershipUI.h"
#include "ManageMember.h"
#include <string>
using namespace std;

class ManageMember;
class JoinMembershipUI;

// Class : JoinMembership
// Description: ȸ������ ����� Control Class
class JoinMembership
{
	JoinMembershipUI* joinMembershipUIPtr;     // JoinMembership ����� boundary class pointer
	ManageMember* manageMemberPtr;             // systemMemberDB ��ü�� �ּҸ� �����ϴ� pointer
public:
	JoinMembership(ManageMember* manageMemberPtr);
	JoinMembershipUI* getJoinMembershipUIPtr();
	void addNewMember(string name, string SSN, string ID, string password);
};

