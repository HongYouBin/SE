#pragma once

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