#pragma once
#include "JoinMembershipUI.h"
#include "JoinMembership.h"
#include <iostream>
using namespace std;
#define MAX_STRING 32

// Function: JoinMembershipUI(JoinMembership* joinMembershipPtr)
// Description: JoinMembershipUI Class�� �Ű����� ������
// Parameter: JoinMembership* joinMembershipPtr- JoinMembership Control Class ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
JoinMembershipUI::JoinMembershipUI(JoinMembership* joinMembershipPtr)
{
	this->joinMembershipPtr = joinMembershipPtr;
}


// Function: startInterface()
// Description: JoinMembership ����� ù ���� ȭ���� ���
// Parameter: None
// Return Value: void
// Author: ������
void JoinMembershipUI::startInterface()
{
	cout << "ȸ������ ������ �Է����ּ���" << endl;
}


// Function: inputPersonalInfo(FILE* in_fp, FILE* out_fp)
// Description: ����ڷκ��� ȸ�� ������ �Է¹ް�, Control Class�� addNewMember �Լ� ȣ��
//              ȸ�� ��� ���� ����� ����ڿ��� ���
// Parameter: FILE* in_fp - �Է� ���� ������, FILE* out_fp - ��� ���� ������
// Return Value: void
// Author: ������
void JoinMembershipUI::inputPersonalInfo(FILE* in_fp, FILE* out_fp)
{
	char name[MAX_STRING], SSN[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
	fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);

	this->joinMembershipPtr->addNewMember(name, SSN, ID, password);

	fprintf(out_fp, "1.1. ȸ������\n");
	fprintf(out_fp, "> %s %s %s %s\n", name, SSN, ID, password);
}
