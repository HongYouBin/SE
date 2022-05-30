#pragma once
#include "Logout.h"
#include <string>
using namespace std;

// Function: Logout(ManageMember* manageMemberPtr)
// Description: Logout Class�� �Ű����� ������
// Parameter: ManageMember* manageMemberPtr - �ý��� ��ü ȸ�� ���� ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
Logout::Logout(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;

}


// Function: logout()
// Description: ���� ����� �α��� ������ �����ϱ� ���� ManageMember class�� deleteLoggedMember�Լ� ȣ��
// Parameter: None
// Return Value: string
// Author: ������
string Logout::logout()
{
	return this->manageMemberPtr->deleteLoggedMember();
}
