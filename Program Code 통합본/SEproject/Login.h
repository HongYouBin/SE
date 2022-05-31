#pragma once
#include "LoginUI.h"
#include "ManageMember.h"

class LoginUI;
class ManageMember;

// Class : Login
// Description: �α��� ����� Control Class
class Login
{
	LoginUI* loginUIPtr;                // Login ����� boundary class pointer
	ManageMember* manageMemberPtr;      // systemMemberDB ��ü�� �ּҸ� �����ϴ� pointer
public:
	Login(ManageMember* manageMemberPtr);
	LoginUI* getLoginUIPtr();
	int checkMember(string ID, string password);

};
