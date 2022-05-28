// ��� ����
#pragma once
#include <stdio.h>
#include <string.h>
#include "ProductList.h"
#include "ManageMember.h"
#include "JoinMembership.h"
#include "Withdrawal.h"
#include "Login.h"
#include "LogoutUI.h"
#include "RegisterSellingClothing.h"
using namespace std;
// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
// �Լ� ����
void doTask();
void program_exit(FILE* out_fp);
// ���� ����
FILE* in_fp, * out_fp;

int main()
{ // ���� ������� ���� �ʱ�ȭ
	FILE* in_fp = fopen(INPUT_FILE_NAME, "r+"); FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");
		doTask();
		return 0;
}

void doTask()
{
	ProductList* systemProductDB = new ProductList;
	ManageMember* systemMemberDB = new ManageMember;
	// �޴� �Ľ��� ���� level ������ ���� ����
	int menu_level_1 = 0, menu_level_2 = 0; int is_program_exit = 0;
	while (!is_program_exit)
	{ // �Է����Ͽ��� �޴� ���� 2���� �б�
		fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);

		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1: // "1.1. ȸ�����ԡ� �޴� �κ�
			{
				JoinMembership* joinMembershipPtr = new JoinMembership(systemMemberDB);
				joinMembershipPtr->getJoinMembershipUIPtr()->inputPersonalInfo(in_fp, out_fp);
				break;
			}
			case 2: // "1.2. ȸ��Ż�� �޴� �κ�
			{
				Withdrawal* withdrawalPtr = new Withdrawal(systemMemberDB);
				withdrawalPtr->getWithdrawalUIPtr()->selectMembershipCancel(out_fp);
				break;
			}
			}
		}
		case 2:
		{
			switch (menu_level_2)
			{
			case 1: // "2.1. �α��Ρ� �޴� �κ�
			{
				Login* loginPtr = new Login(systemMemberDB);
				loginPtr->getLoginUIPtr()->InputIDPW(in_fp, out_fp);
				break;
			}
			case 2: // "2.2. �α׾ƿ��� �޴� �κ�
			{
				LogoutUI* logoutUIPtr = new LogoutUI(systemMemberDB, out_fp);
				break;
			}
			}
		}
		case 3:
		{
			switch (menu_level_2)
			{
			case 1: // "3.1. �Ǹ� �Ƿ� ��ϡ� �޴� �κ�
			{
				RegisterSellingClothing* RegisterSellingClothingPtr = new RegisterSellingClothing(systemProductDB, systemMemberDB);
				RegisterSellingClothingPtr->getRegisterSellingClothingUIPtr()->registerNewProduct(in_fp, out_fp);
				break;
			}
			}
		}
		case 4:
		{
			switch (menu_level_2)
			{
			case 1: // "4.1. �� �޴� �κ�
			{
				
				break;
			}
			case 2: // "4.2. �� �޴� �κ�
			{

				break;
			}
			case 3: // "4.3. �� �޴� �κ�
			{

				break;
			}
			case 4: // "4.4. �� �޴� �κ�
			{

				break;
			}
			}
		}
		case 6:
		{
			switch (menu_level_2)
			{
			case 1: // "6.1. ���ᡰ �޴� �κ�
			{
				program_exit(out_fp);
				is_program_exit = 1;
				break;
			}
			}
		}
		}
	}
	return;
}

void program_exit(FILE* out_fp)
{
	fprintf(out_fp, "6.1. ����\n");
}
	
