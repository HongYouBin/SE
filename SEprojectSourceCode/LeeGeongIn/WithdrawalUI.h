#pragma once

// Class : WithdrawalUI
// Description: ȸ��Ż�� ����� Boundary Class
class WithdrawalUI
{
	Withdrawal* withdrawalPtr;       // Withdrawal ����� control class pointer
public:
	WithdrawalUI(Withdrawal* withdrawalPtr);
	void startInterface();
	void selectMembershipCancel(FILE* out_fp);
};

