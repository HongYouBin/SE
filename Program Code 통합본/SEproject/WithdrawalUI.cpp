#pragma once
#include "WithdrawalUI.h"
#include "Withdrawal.h"
using namespace std;
#include <iostream>
#define MAX_STRING 32

class Withdrawal;
class WithdrawalUI;

// Function: WithdrawalUI(Withdrawal* withdrawalPtr)
// Description: WithdrawalUI Class�� �Ű����� ������
// Parameter: Withdrawal* withdrawalPtr- Withdrawal Control Class ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
WithdrawalUI::WithdrawalUI(Withdrawal* withdrawalPtr)
{
	this->withdrawalPtr = withdrawalPtr;
}


// Function: startInterface()
// Description: Withdrawal ����� ù ���� ȭ���� ���
// Parameter: None
// Return Value: void
// Author: ������
void WithdrawalUI::startInterface()
{
	cout << "Ż���Ͻðڽ��ϱ�?" << endl;
}


// Function: selectMembershipCancel(FILE* out_fp)
// Description: ���� ȸ���� ȸ�������� �����ϴ� Control Class�� cancelMembership �Լ� ȣ��
//              ȸ�� Ż�� ó�� ���� Ż�� ȸ�� ID�� ����ڿ��� ���
// Parameter: FILE* out_fp - ��� ���� ������
// Return Value: void
// Author: ������
void WithdrawalUI::selectMembershipCancel(FILE* out_fp)
{
	char deletedMemberID[MAX_STRING];
	strcpy(deletedMemberID, (this->withdrawalPtr->cancelMembership()).c_str());

	fprintf(out_fp, "1.2. ȸ��Ż��\n");
	fprintf(out_fp, "> %s\n", deletedMemberID);
}
