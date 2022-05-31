#pragma once
#include "WithdrawalUI.h"
#include "ManageMember.h"

class WithdrawalUI;
class ManageMember;

// Class : Withdrawal
// Description: ȸ��Ż�� ����� Control Class
class Withdrawal
{
	WithdrawalUI* withdrawalUIPtr;       // Withdrawal ����� boundary class pointer
	ManageMember* manageMemberPtr;       // systemMemberDB ��ü�� �ּҸ� �����ϴ� pointer
public:
	Withdrawal(ManageMember* manageMemberPtr);
	WithdrawalUI* getWithdrawalUIPtr();
	string cancelMembership();
};
