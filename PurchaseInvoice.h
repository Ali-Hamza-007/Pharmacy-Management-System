#pragma once
#include<string>
class PurchaseInvoice
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
		PurchaseInvoice() {
			invoiceNo = "";
			date = "";
			id = 0;
			quantities = 0;
			price = 0;
			totalPrice = 0;
			discount = 0;
		}
		friend void viewPurchaseSummary(PurchaseInvoice*&, int);
		friend PurchaseInvoice* readPurchaseData(int a, int b, int c);
};

