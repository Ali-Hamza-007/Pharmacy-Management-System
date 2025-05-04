#pragma once
#include<iostream>
#include <string>
using namespace std;
class Supplier
{
private:
	int ID;
	std::string CompanyName;
	std::string RepresentativeName;
	std::string Address;
	std::string Description;
public:
	Supplier() {
		ID = 0;
		CompanyName = "";
		RepresentativeName = "";
		Address = "";
		Description = "";
	}
	friend	Supplier* readSupplierData(int);
	friend void addSupplier(Supplier*& , int&);
	friend void editSupplier(int, Supplier*&, int);
	friend void deleteSupplier(int, Supplier*& , int&);
	void viewAllSupplier();
	friend void viewSupplier(int iid, Supplier*& , int size);
	friend void writeFileSupplier(Supplier*, int);
};


