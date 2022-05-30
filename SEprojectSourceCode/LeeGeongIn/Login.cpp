#pragma once
#include "Login.h"
#include <string>
using namespace std;

// Function: Login(ManageMember* manageMemberPtr)
// Description: Login Class�� �Ű����� ������
// Parameter: ManageMember* manageMemberPtr - �ý��� ��ü ȸ�� ���� ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
Login::Login(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	this->loginUIPtr = new LoginUI(this);
	this->loginUIPtr->startInterface();
}


// Function: getLoginUIPtr()
// Description: LoginUIPtr ��������� getter function
// Parameter: None
// Return Value: LoginUI*
// Author: ������
LoginUI* Login::getLoginUIPtr()
{
	return this->loginUIPtr;
}


// Function: checkMember(string ID, string password)
// Description: ȸ�����Ե� ����ڰ� �´��� Ȯ���ϴ� ManageMember�� checkMember�Լ� ȣ��
// Parameter: string ID - ȸ�� ID, string password - ��й�ȣ
// Return Value: int
// Author: ������
int Login::checkMember(string ID, string password)
{
	return (this->manageMemberPtr->checkMember(ID, password));
}
