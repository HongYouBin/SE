#pragma once
#include "Member.h"
#include <string>
using namespace std;

// Function: Member(string name, string SSN, string ID, string password)
// Description: Member Class�� �Ű����� ������
// Parameter: string name - ȸ����, string SSN - �ֹι�ȣ, string ID - ȸ�� ID, string password - ��й�ȣ
// Return Value: None
// Author: ������
Member::Member(string name, string SSN, string ID, string password)
{
	this->name = name;
	this->SSN = SSN;
	this->ID = ID;
	this->password = password;
}


// Function: getID()
// Description: ID ��������� getter function
// Parameter: None
// Return Value: string
// Author: ������
string Member::getID()
{
	return this->ID;
}

// Function: registerLoggedMember()
// Description: ���� �α����� ȸ�� ��ü�� �ּҸ� �޾ƿ�.
// Parameter: None
// Return Value: Member*
// Author: ������
Member* Member::registerLoggedMember()
{
	return this;
<<<<<<< HEAD
}
=======
}

vector<string> Member::getPurchaseList()
{
	return this->purchaseList;
}
>>>>>>> 692692f77fa93467b94b8bb76c6d7577f8b1ec02