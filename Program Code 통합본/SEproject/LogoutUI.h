#pragma once

// Class : LogoutUI
// Description: �α׾ƿ� ����� Boundary Class
class LogoutUI
{
	Logout* logoutPtr;     // Logout ����� control class pointer
public:
	LogoutUI(Logout* logoutPtr, FILE* out_fp);
	void selectLogout(FILE* out_fp);
};
