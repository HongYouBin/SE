#pragma once

// Class : JoinMembershipUI
// Description: ȸ������ ����� Boundary Class
class JoinMembershipUI
{
	JoinMembership* joinMembershipPtr;      // JoinMembership ����� control class pointer
public:
	JoinMembershipUI(JoinMembership* joinMembershipPtr);
	void startInterface();
	void inputPersonalInfo(FILE* in_fp, FILE* out_fp);
};

