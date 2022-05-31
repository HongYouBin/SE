#pragma once
#include "LoginUI.h"
#include "Login.h"
#include <iostream>
using namespace std;
#define MAX_STRING 32

// Function: LoginUI(Login* loginPtr)
// Description: LoginUI Class�� �Ű����� ������
// Parameter: Login* loginPtr- Login Control Class ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
LoginUI::LoginUI(Login* loginPtr)
{
	this->loginPtr = loginPtr;
}


// Function: InputIDPW(FILE* in_fp, FILE* out_fp)
// Description: ����ڷκ��� ID, password ������ �Է¹ް�, Control Class�� checkMember �Լ� ȣ��
//              ȸ�� ���� üũ ���� �α��� ����� ����ڿ��� ���
// Parameter: FILE* in_fp - �Է� ���� ������, FILE* out_fp - ��� ���� ������
// Return Value: void
// Author: ������
void LoginUI::InputIDPW(FILE* in_fp, FILE* out_fp)
{
	char ID[MAX_STRING], password[MAX_STRING];
	fscanf(in_fp, "%s %s", ID, password);

	int isMember = 0;
	isMember = this->loginPtr->checkMember(ID, password);

	if (isMember == 1)
	{
		fprintf(out_fp, "2.1. �α���\n");
		fprintf(out_fp, "> %s %s\n", ID, password);
	}
	else
	{
		fprintf(out_fp, "2.1. �α���\n");
		fprintf(out_fp, "> ȸ�����Ե��� ���� ������Դϴ�. ȸ�������� �������ּ���.\n");
	}
}


// Function: startInterface()
// Description: Login ����� ù ���� ȭ���� ���
// Parameter: None
// Return Value: void
// Author: ������
void LoginUI::startInterface()
{
	cout << "���̵�� ��й�ȣ�� �Է����ּ���." << endl;
}