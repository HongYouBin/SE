#pragma once
#include "ClassesCollection.h"
#include <stdio.h>
#include <iostream>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STRING 32

// Function: JoinMembership(ManageMember* manageMemberPtr)
// Description: JoinMembership Class�� �Ű����� ������
// Parameter: ManageMember* manageMemberPtr - �ý��� ��ü ȸ�� ���� ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
JoinMembership::JoinMembership(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	JoinMembership* thisClassPtr = this;
	this->joinMembershipUIPtr = new JoinMembershipUI(thisClassPtr);
	this->joinMembershipUIPtr->startInterface();
}


// Function: getJoinMembershipUIPtr()
// Description: JoinMembershipUIPtr ��������� getter function
// Parameter: None
// Return Value: JoinMembershipUI*
// Author: ������
JoinMembershipUI* JoinMembership::getJoinMembershipUIPtr()
{
	return this->joinMembershipUIPtr;
}


// Function: addNewMember(string name, string SSN, string ID, string password)
// Description: �� ȸ���� ��Ͻ�Ű�� ManageMember�� createMember �Լ� ȣ��
// Parameter: string name - ȸ����, string SSN - �ֹι�ȣ, string ID - ȸ�� ID, string password - ��й�ȣ
// Return Value: void
// Author: ������
void JoinMembership::addNewMember(string name, string SSN, string ID, string password)
{
	this->manageMemberPtr->createMember(name, SSN, ID, password);
}

//----------------------------------------------------------------------------------------

// Function: JoinMembershipUI(JoinMembership* joinMembershipPtr)
// Description: JoinMembershipUI Class�� �Ű����� ������
// Parameter: JoinMembership* joinMembershipPtr- JoinMembership Control Class ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
JoinMembershipUI::JoinMembershipUI(JoinMembership* joinMembershipPtr)
{
	this->joinMembershipPtr = joinMembershipPtr;
}


// Function: startInterface()
// Description: JoinMembership ����� ù ���� ȭ���� ���
// Parameter: None
// Return Value: void
// Author: ������
void JoinMembershipUI::startInterface()
{
	cout << "ȸ������ ������ �Է����ּ���" << endl;
}


// Function: inputPersonalInfo(FILE* in_fp, FILE* out_fp)
// Description: ����ڷκ��� ȸ�� ������ �Է¹ް�, Control Class�� addNewMember �Լ� ȣ��
//              ȸ�� ��� ���� ����� ����ڿ��� ���
// Parameter: FILE* in_fp - �Է� ���� ������, FILE* out_fp - ��� ���� ������
// Return Value: void
// Author: ������
void JoinMembershipUI::inputPersonalInfo(FILE* in_fp, FILE* out_fp)
{
	char name[MAX_STRING], SSN[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
	fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);

	this->joinMembershipPtr->addNewMember(name, SSN, ID, password);

	fprintf(out_fp, "1.1. ȸ������\n");
	fprintf(out_fp, "> %s %s %s %s\n", name, SSN, ID, password);
}

//----------------------------------------------------------------------------------------------

// Function: Login(ManageMember* manageMemberPtr)
// Description: Login Class�� �Ű����� ������
// Parameter: ManageMember* manageMemberPtr - �ý��� ��ü ȸ�� ���� ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
Login::Login(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	this->loginUIPtr = new LoginUI(this);
	this->loginUIPtr->startInterface();
}


// Function: getLoginUIPtr()
// Description: LoginUIPtr ��������� getter function
// Parameter: None
// Return Value: LoginUI*
// Author: ������
LoginUI* Login::getLoginUIPtr()
{
	return this->loginUIPtr;
}


// Function: checkMember(string ID, string password)
// Description: ȸ�����Ե� ����ڰ� �´��� Ȯ���ϴ� ManageMember�� checkMember�Լ� ȣ��
// Parameter: string ID - ȸ�� ID, string password - ��й�ȣ
// Return Value: int
// Author: ������
int Login::checkMember(string ID, string password)
{
	return (this->manageMemberPtr->checkMember(ID, password));
}

//------------------------------------------------------------------------------------------

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
		fprintf(out_fp, "> \n");
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

//--------------------------------------------------------------------------------------------

// Function: Logout(ManageMember* manageMemberPtr)
// Description: Logout Class�� �Ű����� ������
// Parameter: ManageMember* manageMemberPtr - �ý��� ��ü ȸ�� ���� ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
Logout::Logout(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;

}


// Function: logout()
// Description: ���� ����� �α��� ������ �����ϱ� ���� ManageMember class�� deleteLoggedMember�Լ� ȣ��
// Parameter: None
// Return Value: string
// Author: ������
string Logout::logout()
{
	return this->manageMemberPtr->deleteLoggedMember();
}

//----------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------

// Function: getSellerID()
// Description: �Ǹ����� ID������ �޾ƿ� return�� ��
// Parameter: None
// Return Value: string
// Author: ������
string ManageMember::getSellerID()
{
	return loggedMembers[0].getID();
}


// Function: createMember(string name, string SSN, string ID, string password)
// Description: �� ȸ���� memberDB�� ����
// Parameter: string name - ȸ����, string SSN - �ֹι�ȣ, string ID - ȸ�� ID, string password - ��й�ȣ
// Return Value: void
// Author: ������
void ManageMember::createMember(string name, string SSN, string ID, string password)
{
	Member* newMember = new Member(name, SSN, ID, password);
	memberDB.push_back(*newMember);
}


// Function: checkMember(string ID, string password)
// Description: ȸ�����Ե� ����ڰ� �´��� Ȯ��
// Parameter: string ID - ȸ�� ID, string password - ��й�ȣ
// Return Value: int
// Author: ������
int ManageMember::checkMember(string ID, string password)
{
	int checkedMemberIndex = -1;
	for (int i = 0; i < memberDB.size(); i++)
	{
		if (memberDB[i].getID() == ID)
		{
			checkedMemberIndex = i;
			break;
		}
	}
	if (checkedMemberIndex < 0)
	{
		return 0;
	}
	else
	{
		Member* loginMember = memberDB[checkedMemberIndex].registerLoggedMember();
		loggedMembers.push_back(*loginMember);
		return 1;
	}
}


// Function: deleteMember()
// Description: ȸ������ ����
// Parameter: None
// Return Value: string
// Author: ������
string ManageMember::deleteMember()
{
	string deleteMemberID = loggedMembers.back().getID();
	int deleteMemberIndex = -1;
	for (int i = 0; i < memberDB.size(); i++)
	{
		if (memberDB[i].getID() == deleteMemberID)
		{
			deleteMemberIndex = i;
			break;
		}
	}
	memberDB.erase(memberDB.begin() + deleteMemberIndex);
	loggedMembers.pop_back();
	return deleteMemberID;
}


// Function: deleteLoggedMember()
// Description: �α��ε� ��� ����Ʈ���� ���� �α��� ��� ����
// Parameter: None
// Return Value: string
// Author: ������
string ManageMember::deleteLoggedMember()
{
	string logoutMemberID = loggedMembers.back().getID();
	loggedMembers.pop_back();
	return logoutMemberID;
}

void ManageMember::addPurchaseList(string productName)        //
{
	loggedMembers[0].addPurchaseList(productName);
}

vector<string> ManageMember::getPurchaseList()            //
{
	return loggedMembers[0].getPurchaseList();
}

//------------------------------------------------------------------------------------------------

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
}

vector<string> Member::getPurchaseList()
{
	return (this->purchaseList);
}

void Member::addPurchaseList(string productName)
{
	this->purchaseList.push_back(productName);
}

//--------------------------------------------------------------------------------------------------

// Function: createProduct(string seller, string name, string company, string price, string quentity)
// Description: ���ο� Product�� ������ ProductDB�� ����.
// Parameter: string seller- �Ǹ��� ID, string name - ��ǰ��, string company - ����ȸ���, string price - ��ǰ����, 
//            string quentity - ��������
// Return Value: void
// Author: ������
void ProductList::createProduct(string seller, string name, string company, string price, string quentity)
{
	Product* newProduct = new Product(seller, name, company, price, stoi(quentity));
	productDB.push_back(*newProduct);
}

Product* ProductList::getProductInfo(string productName)
{
	for (int i = 0; i < productDB.size(); ++i)
	{
		if (productDB[i].getName() == productName)
		{
			return &productDB[i];
		}
	}
}

void ProductList::purchase(Product* productPtr)
{
	// Product tmpProduct = getProductInfo(productName);
	//tmpProduct.purchase();
	productPtr->purchase();
}

Product* ProductList::saveEvaluationInfo(string productName, int evaluation)
{
	Product* productPtr = getProductInfo(productName);
	productPtr->addEvaluation(evaluation);
	return productPtr;
}

//-----------------------------------------------------------------------------------------------------

// Function: Product(string seller, string name, string company, string price, string quentity)
// Description: Product Class�� �Ű����� ������
// Parameter: string seller- �Ǹ��� ID, string name - ��ǰ��, string company - ����ȸ���, string price - ��ǰ����, 
//            int quentity - ��������
// Return Value: None
// Author: ������
Product::Product(string seller, string name, string company, string price, int quentity)
{
	this->seller = seller;
	this->name = name;
	this->company = company;
	this->price = price;
	this->quentity = quentity; 
}

string Product::getName()
{
	return this->name;
}

string Product::getSeller()
{
	return seller;
}

string Product::getPrice()
{
	return price;
}

string Product::getCompany()
{
	return company;
}

int Product::getQuentity()
{
	return quentity;
}

int Product::getEvaluationAverage()
{
	if (numberOfEvaluation == 0) return 0;
	return evaluation / numberOfEvaluation;
}

void Product::purchase()
{
	this->quentity--;
}

Product Product::addEvaluation(int evaluation)
{
	this->evaluation += evaluation;
	this->numberOfEvaluation++;
	return *this;
}

float Product::getAverageEvaluation()
{
	return (static_cast<float>(this->evaluation) / this->numberOfEvaluation);
}

//---------------------------------------------------------------------------------------------------------

// Function: RegisterSellingClothing(ProductList* ProductListPtr, ManageMember* manageMemberPtr)
// Description: RegisterSellingClothing Class�� �Ű����� ������
// Parameter: ProductList* ProductListPtr- �ý��� ��ü ��ǰ ����Ʈ ��ü�� �ּҸ� �޴� ������ �Ű�����, 
//            ManageMember* manageMemberPtr - �ý��� ��ü ȸ�� ���� ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
RegisterSellingClothing::RegisterSellingClothing(ProductList* ProductListPtr, ManageMember* manageMemberPtr)
{
	this->productListPtr = ProductListPtr;
	this->manageMemberPtr = manageMemberPtr;
	this->registerSellingClothingUIPtr = new RegisterSellingClothingUI(this);
	registerSellingClothingUIPtr->startInterface();
}


// Function: getRegisterSellingClothingUIPtr()
// Description: RegisterSellingClothingUIPtr ��������� getter function
// Parameter: None
// Return Value: RegisterSellingClothingUI*
// Author: ������
RegisterSellingClothingUI* RegisterSellingClothing::getRegisterSellingClothingUIPtr()
{
	return this->registerSellingClothingUIPtr;
}


// Function: addNewProduct(string name, string company, string price, string quentity)
// Description: �Ǹ����� ID������ �޾ƿ� �� Product�� ProductDB�� �����ϴ� ProductList�� createProduct�Լ��� ȣ��
// Parameter: string name - ��ǰ��, string company - ����ȸ���, string price - ��ǰ����, string quentity - ��������
// Return Value: void
// Author: ������
void RegisterSellingClothing::addNewProduct(string name, string company, string price, string quentity)
{
	string seller = this->manageMemberPtr->getSellerID();
	this->productListPtr->createProduct(seller, name, company, price, quentity);
}

//-----------------------------------------------------------------------------------------------------------

// Function: RegisterSellingClothingUI(RegisterSellingClothing* registerSellingClothingPtr)
// Description: RegisterSellingClothingUI Class�� �Ű����� ������
// Parameter: RegisterSellingClothing* registerSellingClothingPtr- RegisterSellingClothing Control Class ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
RegisterSellingClothingUI::RegisterSellingClothingUI(RegisterSellingClothing* registerSellingClothingPtr)
{
	this->registerSellingClothingPtr = registerSellingClothingPtr;
}


// Function: startInterface()
// Description: RegisterSellingClothing ����� ù ���� ȭ���� ���
// Parameter: None
// Return Value: void
// Author: ������
void RegisterSellingClothingUI::startInterface()
{
	cout << "����� �Ƿ������� �Է��ϼ���." << endl;
}


// Function: registerNewProduct(FILE* in_fp, FILE* out_fp)
// Description: ����ڷκ��� ����� ��ǰ ������ �Է¹ް�, Control Class�� addNewProduct �Լ� ȣ��
//              ��ǰ ��� ���� ����� ����ڿ��� ���
// Parameter: FILE* in_fp - �Է� ���� ������, FILE* out_fp - ��� ���� ������
// Return Value: void
// Author: ������
void RegisterSellingClothingUI::registerNewProduct(FILE* in_fp, FILE* out_fp)
{
	char name[MAX_STRING], company[MAX_STRING], price[MAX_STRING], quentity[MAX_STRING];
	fscanf(in_fp, "%s %s %s %s", name, company, price, quentity);

	this->registerSellingClothingPtr->addNewProduct(name, company, price, quentity);

	fprintf(out_fp, "3.1 �Ǹ� �Ƿ� ���\n");
	fprintf(out_fp, "> %s %s %s %s\n", name, company, price, quentity);
}

//-----------------------------------------------------------------------------------------------------

// Function: Withdrawal(ManageMember* manageMemberPtr)
// Description: Withdrawal Class�� �Ű����� ������
// Parameter: ManageMember* manageMemberPtr - �ý��� ��ü ȸ�� ���� ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
Withdrawal::Withdrawal(ManageMember* manageMemberPtr)
{
	this->manageMemberPtr = manageMemberPtr;
	this->withdrawalUIPtr = new WithdrawalUI(this);
	withdrawalUIPtr->startInterface();
}


// Function: getWithdrawalUIPtr()
// Description: WithdrawalUIPtr ��������� getter function
// Parameter: None
// Return Value: WithdrawalUI*
// Author: ������
WithdrawalUI* Withdrawal::getWithdrawalUIPtr()
{
	return this->withdrawalUIPtr;
}


// Function: cancelMembership()
// Description: ȸ�� ������ �����ϴ� ManageMember�� deleteMember�Լ� ȣ��
// Parameter: None
// Return Value: string
// Author: ������
string Withdrawal::cancelMembership()
{
	return this->manageMemberPtr->deleteMember();
}

//----------------------------------------------------------------------------------------------------------

// Function: WithdrawalUI(Withdrawal* withdrawalPtr)
// Description: WithdrawalUI Class�� �Ű����� ������
// Parameter: Withdrawal* withdrawalPtr- Withdrawal Control Class ��ü�� �ּҸ� �޴� ������ �Ű�����
// Return Value: None
// Author: ������
WithdrawalUI::WithdrawalUI(Withdrawal* withdrawalPtr)
{
	this->withdrawalPtr = withdrawalPtr;
}


// Function: startInterface()
// Description: Withdrawal ����� ù ���� ȭ���� ���
// Parameter: None
// Return Value: void
// Author: ������
void WithdrawalUI::startInterface()
{
	cout << "Ż���Ͻðڽ��ϱ�?" << endl;
}


// Function: selectMembershipCancel(FILE* out_fp)
// Description: ���� ȸ���� ȸ�������� �����ϴ� Control Class�� cancelMembership �Լ� ȣ��
//              ȸ�� Ż�� ó�� ���� Ż�� ȸ�� ID�� ����ڿ��� ���
// Parameter: FILE* out_fp - ��� ���� ������
// Return Value: void
// Author: ������
void WithdrawalUI::selectMembershipCancel(FILE* out_fp)
{
	char deletedMemberID[MAX_STRING];
	strcpy(deletedMemberID, (this->withdrawalPtr->cancelMembership()).c_str());

	fprintf(out_fp, "1.2. ȸ��Ż��\n");
	fprintf(out_fp, "> %s\n", deletedMemberID);
}


// -----------------------------�߰��� .cpp----------------------

Search::Search(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	this->manageMemberPtr = manageMemberAddress;
	this->productListPtr = productListAddress;
}

Product* Search::searchProduct(string productName)
{
	return productListPtr->getProductInfo(productName);
}

void Search::purchaseProduct(Product* productPtr)
{
	productListPtr->purchase(productPtr);
	manageMemberPtr->addPurchaseList(productPtr->getName());
}

//------------------------------------------------------------

SearchUI::SearchUI(ManageMember* manageMemberPtr, ProductList* productListPtr)
{
	this->searchPtr = new Search(manageMemberPtr, productListPtr);
}

void SearchUI::searchProduct(FILE* productName, FILE* out_fp)
{
	char charSearchName[MAX_STRING];
	fscanf(productName, "%s", charSearchName);
	string searchName(charSearchName);

	selectedProduct = searchPtr->searchProduct(searchName);
	fprintf(out_fp, "4.1 ��ǰ ���� �˻�\n");

	char sellerName[MAX_STRING], name[MAX_STRING], companyName[MAX_STRING], price[MAX_STRING];
	strcpy(sellerName, (selectedProduct->getSeller()).c_str());
	strcpy(name, (selectedProduct->getName()).c_str());
	strcpy(companyName, (selectedProduct->getCompany()).c_str());
	strcpy(price, (selectedProduct->getPrice()).c_str());
	fprintf(out_fp, "> %s %s %s %s %d %.1f \n", sellerName, name, companyName, price, selectedProduct->getQuentity(), selectedProduct->getAverageEvaluation());
}

void SearchUI::purchase(FILE* out_fp)
{
	searchPtr->purchaseProduct(selectedProduct);

	fprintf(out_fp, "4.2 ��ǰ ����\n");
	char sellerName[MAX_STRING], name[MAX_STRING];
	strcpy(sellerName, (selectedProduct->getSeller()).c_str());
	strcpy(name, (selectedProduct->getName()).c_str());
	fprintf(out_fp, "> %s %s\n", sellerName, name);
}

//----------------------------------------------------------

PurchaseList::PurchaseList(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	this->manageMemberPtr = manageMemberAddress;
	this->productListPtr = productListAddress;
}

vector<Product> PurchaseList::getPurchaseList()
{
	vector<string> purchaseListString = manageMemberPtr->getPurchaseList();
	vector<Product> purchasedProductList;
	for (int i = 0; i < purchaseListString.size(); ++i) {
		purchasedProductList.push_back((*productListPtr->getProductInfo(purchaseListString[i])));
		//purchasedProductList.push_back((*productListPtr->getProductInfo((*purchaseListString)[i])));
	}
	return purchasedProductList;
}

//---------------------------------------------------------

PurchaseListUI::PurchaseListUI(ManageMember* manageMemberAddress, ProductList* productListAddress)
{
	this->purchaseListPtr = new PurchaseList(manageMemberAddress, productListAddress);
}

void PurchaseListUI::showProductList(FILE* out_fp)
{
	fprintf(out_fp, "4.3 ��ǰ ���� ���� ��ȸ\n");
	vector<Product> selectedProductList = this->purchaseListPtr->getPurchaseList();

	char sellerName[MAX_STRING], name[MAX_STRING], companyName[MAX_STRING], price[MAX_STRING];
	for (int i = 0; i < selectedProductList.size(); ++i)
	{
		strcpy(sellerName, (selectedProductList[i].getSeller()).c_str());
		strcpy(name, (selectedProductList[i].getName()).c_str());
		strcpy(companyName, (selectedProductList[i].getCompany()).c_str());
		strcpy(price, (selectedProductList[i].getPrice()).c_str());
		fprintf(out_fp, "> %s %s %s %s %d %.1f \n", sellerName, name, companyName, price, selectedProductList[i].getQuentity(), selectedProductList[i].getAverageEvaluation());
	}
	//fprintf(out_fp, "%c %c %c %c %c %c", selectedProduct.);
}

//----------------------------------------------------------

Evaluation::Evaluation(ProductList* productList)
{
	this->productListPtr = productList;
}

Product* Evaluation::saveEvaluation(string productName, int evaluation)
{
	return productListPtr->saveEvaluationInfo(productName, evaluation);
}

//--------------------------------------------------------

EvaluationUI::EvaluationUI(ProductList* productListAddress)
{
	evaluationPtr = new Evaluation(productListAddress);
}

void EvaluationUI::evaluateProduct(FILE* in_fp, FILE* out_fp)
{
	char charProductName[MAX_STRING], evaluation[MAX_STRING];
	fscanf(in_fp, "%s %s", charProductName, evaluation);

	Product* evaluatedProduct = evaluationPtr->saveEvaluation(charProductName, stoi(evaluation));

	fprintf(out_fp, "4.4 ��ǰ ���Ÿ����� ��\n");
	char sellerName[MAX_STRING], name[MAX_STRING];
	strcpy(sellerName, (evaluatedProduct->getSeller()).c_str());
	strcpy(name, (evaluatedProduct->getName()).c_str());
	fprintf(out_fp, "> %s %s %s\n", sellerName, name, evaluation);
}