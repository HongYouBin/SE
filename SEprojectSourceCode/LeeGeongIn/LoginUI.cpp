#pragma once
#include "LoginUI.h"

#define MAX_STRING 32

LoginUI::LoginUI(Login* loginPtr)
{
	this->loginPtr = loginPtr;
}

void LoginUI::InputIDPW(FILE* in_fp, FILE* out_fp)
{
	char ID[MAX_STRING], password[MAX_STRING];
	fscanf(in_fp, "%s %s", ID, password);

	int isMember = 0;
	isMember = this->loginPtr->checkMember(ID, password);
	
	if (isMember == 1)
	{
		fprintf(out_fp, "2.1. �α���\n");
		fprintf(out_fp, "%s %s\n", ID, password);
	}
	else
	{
		fprintf(out_fp, "2.1. �α���\n");
		fprintf(out_fp, "ȸ�����Ե��� ���� ������Դϴ�. ȸ�������� �������ּ���.\n");
	}
}

void LoginUI::startInterface()
{
	cout << "���̵�� ��й�ȣ�� �Է����ּ���." << endl;
}
