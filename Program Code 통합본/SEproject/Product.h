#pragma once
#include <string>
#include <vector>
using namespace std;

// Class : Product
// Description: 물품 정보 저장 Class
class Product
{
	string seller;          // 판매자 ID
	string name;            // 상품명
	string company;         // 상품 생산 회사명
	string price;           // 상품 가격
	int quentity;        // 수량
	int evaluation = 0;     // 구매만족도
	int numberOfEvaluation;		//구매만족도에 참여한 인원

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

