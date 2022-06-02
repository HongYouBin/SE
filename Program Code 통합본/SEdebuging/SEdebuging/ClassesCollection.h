#pragma once
#include <vector>
#include <string>
using namespace std;

class JoinMembership;
class JoinMembershipUI;
class Login;
class LoginUI;
class Logout;
class LogoutUI;
class ManageMember;
class Member;
class ProductList;
class Product;
class RegisterSellingClothing;
class RegisterSellingClothingUI;
class Withdrawal;
class WithdrawalUI;
class Search;
class SearchUI;
class PurchaseList;
class PurchaseListUI;
class Evaluation;
class EvaluationUI;

// Class : JoinMembership
// Description: ȸ������ ����� Control Class
class JoinMembership
{
	JoinMembershipUI* joinMembershipUIPtr;     // JoinMembership ����� boundary class pointer
	ManageMember* manageMemberPtr;             // systemMemberDB ��ü�� �ּҸ� �����ϴ� pointer
public:
	JoinMembership(ManageMember* manageMemberPtr);
	JoinMembershipUI* getJoinMembershipUIPtr();
	void addNewMember(string name, string SSN, string ID, string password);
};

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

// Class : Login
// Description: �α��� ����� Control Class
class Login
{
	LoginUI* loginUIPtr;                // Login ����� boundary class pointer
	ManageMember* manageMemberPtr;      // systemMemberDB ��ü�� �ּҸ� �����ϴ� pointer
public:
	Login(ManageMember* manageMemberPtr);
	LoginUI* getLoginUIPtr();
	int checkMember(string ID, string password);

};

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

// Class : Logout
// Description: �α׾ƿ� ����� Control Class
class Logout
{
	ManageMember* manageMemberPtr;       // systemMemberDB ��ü�� �ּҸ� �����ϴ� pointer
public:
	Logout(ManageMember* manageMemberPtr);
	string logout();
};

// Class : LogoutUI
// Description: �α׾ƿ� ����� Boundary Class
class LogoutUI
{
	Logout* logoutPtr;     // Logout ����� control class pointer
public:
	LogoutUI(Logout* logoutPtr, FILE* out_fp);
	void selectLogout(FILE* out_fp);
};


// Class : ManageMember
// Description: �ý��� �� ȸ�� ����Ʈ ���� �� �α��� ȸ�� ���� ����, ȸ�� ���� Ȯ���� ���� Class
class ManageMember
{
	vector<Member> memberDB;          // ���θ� ���α׷��� �����ϴ� ��ü ȸ�� ���� vector
	vector<Member> loggedMembers;     // ���� ���θ� ���α׷��� �α����� ȸ�� ���� vector
public:
	string getSellerID();
	void createMember(string name, string SSN, string ID, string password);
	int checkMember(string ID, string password);
	string deleteMember();
	string deleteLoggedMember();
	void addPurchaseList(string productName);
	vector<string> getPurchaseList();
};

// Class : Member
// Description: ȸ�� ���� ���� Class
class Member
{
	string name;                        // ȸ����
	string ID;                          // ȸ�� ID
	string SSN;                         // �ֹι�ȣ
	string password;                    // ��й�ȣ
	vector<string> purchaseList;        // �ش� ȸ���� ���� ��ǰ���� �����ϴ� vector
public:
	Member(string name, string SSN, string ID, string password);
	string getID();
	Member* registerLoggedMember();
	vector<string> getPurchaseList();
	void addPurchaseList(string productName);
};

// Class : ProductList
// Description: �ý��� �� ��ǰ ����Ʈ ���� Class
class ProductList
{
	vector<Product> productDB;          // ���θ� ���α׷��� �����ϴ� ��ü ��ǰ ���� vector
public:
	void createProduct(string seller, string name, string company, string price, string quentity);
	Product* getProductInfo(string productName);
	void purchase(Product* productName);
	Product* saveEvaluationInfo(string productName, int evaluation);
};

// Class : Product
// Description: ��ǰ ���� ���� Class
class Product
{
	string seller;                  // �Ǹ��� ID
	string name;                    // ��ǰ��
	string company;                 // ��ǰ ���� ȸ���
	string price;                   // ��ǰ ����
	int quentity;                   // ����
	int evaluation = 0;             // ���Ÿ�����
	int numberOfEvaluation = 0;		//���Ÿ������� ������ �ο� 
public:
	Product(string seller, string name, string company, string price, int quentity);
	string getName();
	string getSeller();
	string getPrice();
	string getCompany();
	int getQuentity();
	int getEvaluationAverage();
	void purchase();
	Product addEvaluation(int evaluation);
	float getAverageEvaluation();
};

// Class : RegisterSellingClothing
// Description: �Ǹ� ��ǰ ��� ����� Control Class
class RegisterSellingClothing
{
	RegisterSellingClothingUI* registerSellingClothingUIPtr;   // RegisterSellingClothing ����� boundary class pointer
	ProductList* productListPtr;                               // systemProductDB ��ü�� �ּҸ� �����ϴ� pointer
	ManageMember* manageMemberPtr;                             // systemMemberDB ��ü�� �ּҸ� �����ϴ� pointer
public:
	RegisterSellingClothing(ProductList* productListPtr, ManageMember* manageMemberPtr);
	RegisterSellingClothingUI* getRegisterSellingClothingUIPtr();
	void addNewProduct(string name, string company, string price, string quentity);
};

// Class : RegisterSellingClothingUI
// Description: �Ǹ� ��ǰ ��� ����� Boundary Class
class RegisterSellingClothingUI
{
	RegisterSellingClothing* registerSellingClothingPtr;     // RegisterSellingClothing ����� control class pointer

public:
	RegisterSellingClothingUI(RegisterSellingClothing* registerSellingClothingPtr);
	void startInterface();
	void registerNewProduct(FILE* in_fp, FILE* out_fp);

};

// Class : Withdrawal
// Description: ȸ��Ż�� ����� Control Class
class Withdrawal
{
	WithdrawalUI* withdrawalUIPtr;       // Withdrawal ����� boundary class pointer
	ManageMember* manageMemberPtr;       // systemMemberDB ��ü�� �ּҸ� �����ϴ� pointer
public:
	Withdrawal(ManageMember* manageMemberPtr);
	WithdrawalUI* getWithdrawalUIPtr();
	string cancelMembership();
};

// Class : WithdrawalUI
// Description: ȸ��Ż�� ����� Boundary Class
class WithdrawalUI
{
	Withdrawal* withdrawalPtr;       // Withdrawal ����� control class pointer
public:
	WithdrawalUI(Withdrawal* withdrawalPtr);
	void startInterface();
	void selectMembershipCancel(FILE* out_fp);
};

// Class : Search
// Description: �˻��� ���� ����� Control Class
class Search
{
private:
	ProductList* productListPtr;		// systemProductDB ��ü�� �ּҸ� �����ϴ� pointer
	ManageMember* manageMemberPtr;		// systemMemberDB ��ü�� �ּҸ� �����ϴ� pointer
public:
	Search(ManageMember* manageMemberAddress, ProductList* productListAddress);
	Product* searchProduct(string productName);
	void purchaseProduct(Product* productPtr);
};

// Class : SearchUI
// Description: �˻��� ���� ����� Boundary Class
class SearchUI
{
private:
	Search* searchPtr;		        //SearchUI�� Control Class�� Search Class�� ���� �����ϴ� ������
	Product* selectedProduct;		//�˻� ����� ���� �޾ƿ� Product���� �����ϴ� ������
public:
	SearchUI(ManageMember* manageMemberPtr, ProductList* productListPtr);
	void searchProduct(FILE* productName, FILE* out_fp);
	void purchase(FILE* out_fp);
};

// Class : PurchaseList
// Description: ���ų��� ��ȸ ����� �����ִ� Control Class
class PurchaseList
{
private:
	ProductList* productListPtr;		// systemProductDB ��ü�� �ּҸ� �����ϴ� pointer
	ManageMember* manageMemberPtr;		// systemMemberDB ��ü�� �ּҸ� �����ϴ� pointer
public:
	PurchaseList(ManageMember* manageMemberAddress, ProductList* productListAddress);
	vector<Product> getPurchaseList();
};

// Class : PurchaseListUI
// Description: ���ų��� ��ȸ ����� �ϴ� Boundary Class
class PurchaseListUI
{
private:
	PurchaseList* purchaseListPtr;		// PurchaseListUI�� Control Class�� PurchaseList Class���� �����ϴ� ������
public:
	PurchaseListUI(ManageMember* manageMemberAddress, ProductList* productListAddress);
	void showProductList(FILE* out_fp);
};

// Class : Evaluation
// Description: ��ǰ �� ����� Control Class
class Evaluation
{
private:
	ProductList* productListPtr;		// systemProductDB ��ü�� �ּҸ� �����ϴ� pointer
public:
	Evaluation(ProductList* productList);
	Product* saveEvaluation(string productName, int evaluation);
};

// Class : EvaluationUI
// Description: ��ǰ �� ����� Boundary Class
class EvaluationUI
{
private:
	Evaluation* evaluationPtr;		// EvaluationUI�� Control Class�� Evaluatijon Class���� �����ϴ� ������
public:
	EvaluationUI(ProductList* productListAddress);
	void evaluateProduct(FILE* in_fp, FILE* out_fp);
};