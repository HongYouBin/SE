#pragma once

// Class : LoginUI
// Description: �α��� ����� Boundary Class
class LoginUI
{
	Login* loginPtr;           // Login ����� control class pointer
public:
	LoginUI(Login* loginPtr);

	void InputIDPW(FILE* in_fp, FILE* out_fp);
	void startInterface();
};

