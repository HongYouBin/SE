#pragma once
#include "JoinMembershipUI.h"
#include <iostream>
#include "JoinMembership.h"

using namespace std;
#define MAX_STRING 32

JoinMembershipUI::JoinMembershipUI(JoinMembership* joinMembershipPtr)
{
	this->joinMembershipPtr = joinMembershipPtr;
}

void JoinMembershipUI::startInterface()
{
	cout << "ȸ������ ������ �Է����ּ���" << endl;
}

void JoinMembershipUI::inputPersonalInfo(FILE* in_fp, FILE* out_fp)
{
	char name[MAX_STRING], SSN[MAX_STRING],ID[MAX_STRING], password[MAX_STRING];
	fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);

	this->joinMembershipPtr->addNewMember(name, SSN, ID, password);

	fprintf(out_fp, "1.1. ȸ������\n");
	fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}
