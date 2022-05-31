#pragma once
#include "JoinMembership.h"
#include <string>

// Function: JoinMembership(ManageMember* manageMemberPtr)
// Description: JoinMembership Class�� �Ű����� ������
// Parameter: ManageMember* manageMemberPtr - �ý��� ��ü ȸ�� ���� ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
JoinMembership::JoinMembership(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	JoinMembership* thisClassPtr = this;
	this->joinMembershipUIPtr = new JoinMembershipUI(thisClassPtr);
	this->joinMembershipUIPtr->startInterface();
}


// Function: getJoinMembershipUIPtr()
// Description: JoinMembershipUIPtr ��������� getter function
// Parameter: None
// Return Value: JoinMembershipUI*
// Author: ������
JoinMembershipUI* JoinMembership::getJoinMembershipUIPtr()
{
	return this->joinMembershipUIPtr;
}


// Function: addNewMember(string name, string SSN, string ID, string password)
// Description: �� ȸ���� ��Ͻ�Ű�� ManageMember�� createMember �Լ� ȣ��
// Parameter: string name - ȸ����, string SSN - �ֹι�ȣ, string ID - ȸ�� ID, string password - ��й�ȣ
// Return Value: void
// Author: ������
void JoinMembership::addNewMember(string name, string SSN, string ID, string password)
{
	this->manageMemberPtr->createMember(name, SSN, ID, password);
}
