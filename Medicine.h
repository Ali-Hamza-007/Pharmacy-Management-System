#pragma once
#include<string>
#include<iostream>
using namespace std;
class Medicine
{private:
	int ID;
	string Name;
	float Potency;
	string Manufacturer;
	int Quantity;
	double pricePerUnit;
public:
	Medicine() {
		ID = 0;
        Name = "";
		Potency = 0;
		Manufacturer = "";
		Quantity = 0;
		pricePerUnit = 0;


	}
	int getID();
	double getPriceperUnit();
	Medicine operator-(int soldQuantity);
	Medicine operator+(int addQuantity);
    friend	Medicine* readMedicineData();
    friend void addMed(Medicine* &a,int&);
	friend void editMed(int , Medicine*&,int  );
	friend void deleteMed(int, Medicine*& arr, int&);
	friend void viewMed(int iid, Medicine *&arr,int size);
	friend void writeFileMed(Medicine *,int);
	friend void viewStock(Medicine*& ar, int size);//
};

