#pragma once
#include "Withdrawal.h"
#include <string>
using namespace std;

// Function: Withdrawal(ManageMember* manageMemberPtr)
// Description: Withdrawal Class�� �Ű����� ������
// Parameter: ManageMember* manageMemberPtr - �ý��� ��ü ȸ�� ���� ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
Withdrawal::Withdrawal(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	this->withdrawalUIPtr = new WithdrawalUI(this);
	withdrawalUIPtr->startInterface();
}


// Function: getWithdrawalUIPtr()
// Description: WithdrawalUIPtr ��������� getter function
// Parameter: None
// Return Value: WithdrawalUI*
// Author: ������
WithdrawalUI* Withdrawal::getWithdrawalUIPtr()
{
	return this->withdrawalUIPtr;
}


// Function: cancelMembership()
// Description: ȸ�� ������ �����ϴ� ManageMember�� deleteMember�Լ� ȣ��
// Parameter: None
// Return Value: string
// Author: ������
string Withdrawal::cancelMembership()
{
	return this->manageMemberPtr->deleteMember();
}
