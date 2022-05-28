#pragma once
#include "WithdrawalUI.h"
#include <iostream>
#include "Withdrawal.h"
using namespace std;

WithdrawalUI::WithdrawalUI(Withdrawal* withdrawalPtr)
{
	this->withdrawalPtr = withdrawalPtr;
}

void WithdrawalUI::startInterface()
{
	cout << "Ż���Ͻðڽ��ϱ�?" << endl;
}

void WithdrawalUI::selectMembershipCancel(FILE* out_fp)
{
	string deletedMemberID = this->withdrawalPtr->cancelMembership();

	fprintf(out_fp, "1.2. ȸ��Ż��\n");
	fprintf(out_fp, "%s\n", deletedMemberID);
}
