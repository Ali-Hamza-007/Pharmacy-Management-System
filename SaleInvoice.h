#pragma once
#include<string>
class SaleInvoice
{
private:
	std::string invoiceNo;
	std::string date;
	int id;
	int quantities;
	float price;
	double totalPrice;
	float discount;
public:
	SaleInvoice() {
		invoiceNo = "";
		date = "";
		id = 0;
		quantities = 0;
		price = 0;
		totalPrice = 0;
		discount = 0;

	}
	friend void viewSaleSummary(SaleInvoice*&,int);
	friend SaleInvoice* readSalesData(int a, int b);
};

