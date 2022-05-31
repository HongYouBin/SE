#pragma once
#include "LogoutUI.h"
#include "Logout.h"
#include <string>
using namespace std;
#define MAX_STRING 32

class Logout;

// Function: LogoutUI(Logout* logoutPtr, FILE* out_fp)
// Description: LogoutUI Class�� �Ű����� ������
// Parameter: Logout* logoutPtr- Logout Control Class ��ü�� �ּҸ� �޴� ������ �Ű�����, FILE* out_fp - ��� ���� ������
// Return Value: None
// Author: ������
LogoutUI::LogoutUI(Logout* logoutPtr, FILE* out_fp)
{
	this->logoutPtr = logoutPtr;
	this->selectLogout(out_fp);
}


// Function: selectLogout(FILE* out_fp)
// Description: ���� �α��ε� ȸ���� �α׾ƿ� ó���ϴ� Control Class�� logout �Լ� ȣ��
//              �α׾ƿ� ó�� ���� Ż�� ȸ�� ID�� ����ڿ��� ���
// Parameter: FILE* out_fp - ��� ���� ������
// Return Value: void
// Author: ������
void LogoutUI::selectLogout(FILE* out_fp)
{
	char logoutID[MAX_STRING];
	strcpy(logoutID, (this->logoutPtr->logout()).c_str());
	fprintf(out_fp, "2.2. �α׾ƿ�\n");
	fprintf(out_fp, "> %s\n", logoutID);
}
