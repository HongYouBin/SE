#pragma once
#include "ManageMember.h"

class ManageMember;

// Class : Logout
// Description: �α׾ƿ� ����� Control Class
class Logout
{
	ManageMember* manageMemberPtr;       // systemMemberDB ��ü�� �ּҸ� �����ϴ� pointer
public:
	Logout(ManageMember* manageMemberPtr);
	string logout();
};

