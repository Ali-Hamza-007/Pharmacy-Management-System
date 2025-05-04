#include "Medicine.h"
#include<iostream>
//void Medicine::viewStock() {
//	cout << this->ID<<"  ";
//	cout << this->Name<<"  ";
//	cout << this->Potency<<"  ";
//	cout << this->Manufacturer<<"  ";
//	cout << this->Quantity<<"  ";
//	cout << this->pricePerUnit<<"  ";
//	cout << endl;
//	
//}

int Medicine::getID() {
	return this->ID;
}
double Medicine::getPriceperUnit() {
	return this->pricePerUnit;
}
Medicine Medicine::operator-(int soldQuantity) {
	this->Quantity=this->Quantity - soldQuantity;
	return *this;

}
Medicine Medicine::operator+(int addQuantity) {
	this->Quantity=this->Quantity + addQuantity;
	return *this;
}