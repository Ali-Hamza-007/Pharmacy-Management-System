#include "Supplier.h"
#include<iostream>
using namespace std;
void Supplier::viewAllSupplier() {
	cout << this->ID <<endl;
	cout << this->CompanyName <<endl;
	cout << this->RepresentativeName << endl;
	cout << this->Address <<endl;
	cout << this->Description <<endl;
	cout << endl;

}