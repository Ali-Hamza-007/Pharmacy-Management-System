#include <iostream>
#include <fstream>
#include <string>
#include"Medicine.h"
#include"Supplier.h"
#include"SaleInvoice.h"
#include"PurchaseInvoice.h"
using namespace std;
void viewPurchaseSummary(PurchaseInvoice*&ar, int size) {
    cout << "InvoiceNo  " << "Date  " << "ID  " << "Quantities  " << "Price  " << "TotalPrice  " << "Discount " << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << ar[i].invoiceNo << "  ";
        cout << ar[i].date << "  ";
        cout << ar[i].id << "  ";
        cout << ar[i].quantities << "  ";
        cout << ar[i].price << "  ";
        cout << ar[i].totalPrice << "  ";
        cout << ar[i].discount << "  ";
        cout << endl;
    }
}
void viewSaleSummary(SaleInvoice*& ar, int size) {
    cout << "InvoiceNo  " << "Date  " << "ID  " << "Quantities  " << "Price  " << "TotalPrice  " << "Discount " << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << ar[i].invoiceNo << "  ";
        cout << ar[i].date << "  ";
        cout << ar[i].id << "  ";
        cout << ar[i].quantities << "  ";
        cout << ar[i].price << "  ";
        cout << ar[i].totalPrice << "  ";
        cout << ar[i].discount << "  ";
        cout << endl;
    }
}
void viewStock(Medicine *&ar,int size) {
    cout << "ID  " <<"Name  "  << "Potency  " << "Manufacturer "<< "Quantity  "<< "PricePerUnit" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << ar[i].ID << "  ";
        cout << ar[i].Name << "  ";
        cout << ar[i].Potency << "  ";
        cout << ar[i].Manufacturer << "  ";
        cout << ar[i].Quantity << "  ";
        cout << "$" << ar[i].pricePerUnit << "  ";
        cout << endl;
        
    }
    }
void displayMenu() {
    cout << ">>>>>>>>>>>>>>>>>>>> PHARMACY MANAGEMENT SYSTEM >>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "1. Manage Medicine " << endl;
    cout << "2. Manage Supplier " << endl;
    cout << "3. Record Sale " << endl;
    cout << "4. Record Purchase " << endl;
    cout << "5. Generate Reports" << endl;
    cout << "6. Exit " << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "--------------------------------------------------" << endl;
}
int optionSelection() {
    int option;
    displayMenu();
    do {
        cout << "Select option : ";
        cin >> option;
    } while ((option < 1) || (option > 6));
    return option;
}
int rowsCountMed() {
    ifstream fin("Medicine.txt", ios::in);
    int rowsCount = 0;
    if (!fin.fail()) {
        string line;
        while (getline(fin, line)) {
            rowsCount++;
        }
    }
    fin.close();
    return rowsCount / 6;
}
int rowsCountSales() {
    ifstream fin("SaleInvoice.txt", ios::in);
    int rowsCount = 0;
    if (!fin.fail()) {
        string line;
        while (getline(fin, line)) {
            rowsCount++;
        }
    }
    fin.close();
   
    return rowsCount / 7 +1;
}
int rowsCountPurchase() {
    ifstream fin("PurchaseInvoice.txt", ios::in);
    int rowsCount = 0;
    if (!fin.fail()) {
        string line;
        while (getline(fin, line)) {
            rowsCount++;
        }
    }
    fin.close();
    
    return rowsCount / 7+1;
}
Medicine* readMedicineData()
{
    const int size = rowsCountMed();
    Medicine* MedicineArr = new Medicine[size];
    ifstream fin("Medicine.txt", ios::in);
    if (!fin.fail()) {
        for (int i = 0; i < size; i++) {
            fin >> MedicineArr[i].ID;
            fin >> MedicineArr[i].Name;
            fin >> MedicineArr[i].Potency;
            fin >> MedicineArr[i].Manufacturer;
            fin >> MedicineArr[i].Quantity;
            fin >> MedicineArr[i].pricePerUnit;
        }
    }

    fin.close();
    return MedicineArr;
}
void addMed(Medicine*& a, int& size) {
    Medicine* b = new Medicine[size + 1];
    for (int i = 0; i < size; i++) {
        b[i].ID = a[i].ID;
        b[i].Name = a[i].Name;
        b[i].Potency = a[i].Potency;
        b[i].Manufacturer = a[i].Manufacturer;
        b[i].Quantity = a[i].Quantity;
        b[i].pricePerUnit = a[i].pricePerUnit;
    }
    delete[] a;
    a = b; // Assign b to a 
    size++;
    int ID;
    string Name1;
    float Potency;
    string Manufacturer1;
    int Quantity;
    double pricePerUnit;
    do {
        cout << "Enter ID : ";
        cin >> ID;
    } while (ID < 0);
    a[size - 1].ID = ID;
    cin.ignore();
    cout << "Enter Name In CamelCase Instead of Spaces between Two Words otherWise it Will Generate Errors : ";
    getline(cin, Name1);
    a[size - 1].Name = Name1;
    //  cin.ignore();

    do {
        cout << "Enter Potency : ";
        cin >> Potency;
    } while (Potency < 0);
    a[size - 1].Potency = Potency;
    cin.ignore();
    cout << "Enter Manufacturer Name : ";
    getline(cin, Manufacturer1);
    a[size - 1].Manufacturer = Manufacturer1;

    do {
        cout << "Enter Quantity : ";
        cin >> Quantity;
    } while (Quantity < 0);
    a[size - 1].Quantity = Quantity;
    do {
        cout << "Enter Price per Unit: ";
        cin >> pricePerUnit;
    } while (pricePerUnit < 0);
    a[size - 1].pricePerUnit = pricePerUnit;

}
void editMed(int id, Medicine*& a, int size) {
    string Name1;
    float Potency;
    string Manufacturer1;
    int Quantity;
    double pricePerUnit;
    for (int i = 0; i < size; i++) {
        if (a[i].ID == id) {
            cin.ignore();
            cout << "Enter Name : ";
            getline(cin, Name1);
            a[i].Name = Name1;
            do {
                cout << "Enter Potency : ";
                cin >> Potency;
            } while (Potency < 0);
            a[i].Potency = Potency;
            cin.ignore();
            cout << "Enter Manufacturer Name : ";
            getline(cin, Manufacturer1);
            a[i].Manufacturer = Manufacturer1;
            do {
                cout << "Enter Quantity : ";
                cin >> Quantity;
            } while (Quantity < 0);
            a[i].Quantity = Quantity;
            do {
                cout << "Enter Price per Unit: ";
                cin >> pricePerUnit;
            } while (pricePerUnit < 0);
            a[i].pricePerUnit = pricePerUnit;
            return;
        }
    }
    cout << "No record found with ID " << id << endl;
}
void writeFileMed(Medicine* arr, int size) {
    ofstream fout("Medicine.txt", ios::trunc);
    if (!fout.fail()) {
        for (int i = 0; i < size; i++) {
            fout << arr[i].ID << endl;

            fout << arr[i].Name << endl;
            fout << arr[i].Potency << endl;
            fout << arr[i].Manufacturer << endl;
            fout << arr[i].Quantity << endl;
            fout << arr[i].pricePerUnit << endl;
        }
    }

    fout.close();
}
void deleteMed(int id, Medicine*& arr, int& size) {
    for (int i = 0; i < size; i++) {
        if (arr[i].ID == id) {
            // Shift elements to the left
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            return; // Exit 
        }
    }
}
void viewMed(int iid, Medicine*& arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i].ID == iid) {
            cout << "ID : " << arr[i].ID << endl;
            cout << "Name : " << arr[i].Name << endl;
            cout << "Potency : " << arr[i].Potency << endl;
            cout << "Manufacturer Name : " << arr[i].Manufacturer << endl;
            cout << "Quantity : " << arr[i].Quantity << endl;
            cout << "Price Per Unit : " << arr[i].pricePerUnit << endl;
        }
    }

}
int rowsCountSupplier() {
    ifstream fin("Supplier.txt", ios::in);
    int rowsCount = 0;
    if (!fin.fail()) {
        string line;
        while (getline(fin, line)) {
            rowsCount++;
        }
    }
    fin.close();
    
    return rowsCount ;
   
}
Supplier* readSupplierData(int dummy) {
     int size = rowsCountSupplier();
    Supplier* SupplierArr = new Supplier[size];
    ifstream fin("Supplier.txt", ios::in);
    if (!fin.fail()) {
        for (int i = 0; i < size; i++) {

            fin >> SupplierArr[i].ID;
            string s;
            getline(fin, s);
            SupplierArr[i].CompanyName = s;
            getline(fin, s);
            SupplierArr[i].RepresentativeName = s;
            getline(fin, s);
            SupplierArr[i].Address = s;
            getline(fin, s);
            SupplierArr[i].Description = s;
        }
    }

    fin.close();
    return SupplierArr;
}
void addSupplier(Supplier*& a, int& size) {
    Supplier* b = new Supplier[size + 1];
    for (int i = 0; i < size; i++) {
        b[i].ID = a[i].ID;
        b[i].CompanyName = a[i].CompanyName;
        b[i].RepresentativeName = a[i].RepresentativeName;
        b[i].Address = a[i].Address;
        b[i].Description = a[i].Description;

    }
   /* for (int i = 0; i < size; i++) {
      cout<<  a[i].ID<<endl;
      cout << a[i].CompanyName << endl;
      cout << a[i].RepresentativeName << endl;
      cout << a[i].Address << endl;
      cout << a[i].Description << endl;

    }*/
    delete[] a;
    a = b; // Assign b to a 
    size++;
    int ID;
    string Name1;
    string Manufacturer1;
    string address;
    string desc;

    do {
        cout << "Enter ID Of Supplier : ";
        cin >> ID;
    } while (ID < 0);
    a[size - 1].ID = ID;
    cin.ignore();
    cout << "Enter Company Name In CamelCase Instead of Spaces between Two Words otherWise it Will Generate Errors: ";
    getline(cin, Name1);    
    a[size - 1].CompanyName = Name1;
   //  cin.ignore();


    cout << "Enter Representative Name In CamelCase Instead of Spaces between Two Words otherWise it Will Generate Errors : ";
    getline(cin, Manufacturer1);
    a[size - 1].RepresentativeName = Manufacturer1;
    //cin.ignore();
    cout << "Enter Address In CamelCase Instead of Spaces between Two Words otherWise it Will Generate Errors : ";
    getline(cin, address);
    a[size - 1].Address = address;
    //cin.ignore();
    cout << "Enter Description In CamelCase Instead of Spaces between Two Words otherWise it Will Generate Errors : ";
    getline(cin, desc);
    a[size - 1].Description = desc;
    // cin.ignore();


}
void editSupplier(int id, Supplier*& a, int size) {
    string Name1;
    string Manufacturer1;
    string address;
    string desc;
    for (int i = 0; i < size; i++) {
        if (a[i].ID == id) {
            cin.ignore();
            cout << "Enter Company Name : ";
            getline(cin, Name1);
            a[i].CompanyName = Name1;
            //  cin.ignore();


            cout << "Enter Representative Name : ";
            getline(cin, Manufacturer1);
            a[i].RepresentativeName = Manufacturer1;
         //   cin.ignore();
            cout << "Enter Address : ";
            getline(cin, address);
            a[i].Address = address;
          //  cin.ignore();
            cout << "Enter Description : ";
            getline(cin, desc);
            a[i].Description = desc;
            // cin.ignore();
            return;
        }
    }
    cout << "No record found with ID " << id << endl;
}
void deleteSupplier(int id, Supplier*& arr, int& size) {
    for (int i = 0; i < size; i++) {
        if (arr[i].ID == id) {
            // Shift elements to the left
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            return; // Exit 
        }
    }
}
void viewSupplier(int iid, Supplier*& arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i].ID == iid) {
            cout << "ID : " << arr[i].ID << endl;
            cout << "Company Name : " << arr[i].CompanyName << endl;
            cout << "Representative Name : " << arr[i].RepresentativeName << endl;
            cout << "Address : " << arr[i].Address << endl;
            cout << "Description : " << arr[i].Description << endl;
        }
    }

}
void writeFileSupplier(Supplier* arr, int size) {
    ofstream fout("Supplier.txt", ios::out);
    if (!fout.fail()) {
        for (int i = 0; i < size; i++) {
            
            fout << arr[i].ID << "\t";
            fout << arr[i].CompanyName << "\t";
            fout << arr[i].RepresentativeName << "\t";
            fout << arr[i].Address << "\t";
            fout << arr[i].Description<<"\n";

        }
    }

    fout.close();
}
SaleInvoice* readSalesData(int a, int b) {
     int size = rowsCountSales();
    SaleInvoice* SaleArr = new SaleInvoice[size];
    ifstream fin("SaleInvoice.txt", ios::in);
    if (!fin.fail()) {
        for (int i = 0; i < size; i++) {
            string s;
            getline(fin, s);
            SaleArr[i].invoiceNo = s;
            getline(fin, s);
            SaleArr[i].date = s;
           
            fin >> SaleArr[i].id;
            fin >> SaleArr[i].quantities;
            fin >> SaleArr[i].price;
            fin >> SaleArr[i].totalPrice;
            fin >> SaleArr[i].discount;
            fin.ignore();
        
        }
    }

    fin.close();
    return SaleArr;
}
PurchaseInvoice* readPurchaseData(int a, int b, int c) {
    const int size = rowsCountPurchase();
    PurchaseInvoice* PurchaseArr = new PurchaseInvoice[size];
    ifstream fin("PurchaseInvoice.txt", ios::in);
    if (!fin.fail()) {
        for (int i = 0; i < size; i++) {
            string s;
            getline(fin, s);
            PurchaseArr[i].invoiceNo = s;
            getline(fin, s);
            PurchaseArr[i].date = s;
            fin >> PurchaseArr[i].id;
            fin >> PurchaseArr[i].quantities;
            fin >> PurchaseArr[i].price;
            fin >> PurchaseArr[i].totalPrice;
            fin >> PurchaseArr[i].discount;
            fin.ignore();
        }
    }

    fin.close();
    return PurchaseArr;
}
int main() {
	
	int option=optionSelection();
	Medicine *arr= readMedicineData();
	Supplier* sArr = readSupplierData(0);
	SaleInvoice* saleArr = readSalesData(0, 0);
	PurchaseInvoice* purchaseArr = readPurchaseData(1,1,1);
	 int Msize = rowsCountMed();
	 int Ssize = rowsCountSupplier();
	 int saleSize = rowsCountSales();
    // cout << "SalesInvice Rows " << saleSize<<endl;
	 int purchaseSize = rowsCountPurchase();

	/*for (int i = 0; i < Ssize; i++) {
        sArr[i].viewAllSupplier();
	}*/
	// Manage Medicine
	if (option == 1) {
		cout << "----- Manage Medicine -----" << endl;
		cout << "a.Add Medicine " << endl;
		cout << "b.Edit Medicine " << endl;
		cout << "c.Delete Medicine " << endl;
		cout << "d.View Stock " << endl;
		cout << "--------------------------------" << endl;
		cout << "--------------------------------" << endl;
		char medOption;
		do {
			cout << "Select option : ";
			cin >> medOption;
		} while ((medOption < 'a') || (medOption > 'd') );
		switch (medOption) {
		case 'a': 		// Add medicine
			addMed(arr,Msize);
			break; 
		case 'b':  // Edit medicine
			int id;
			do {
				cout << "Enter ID of Medicine you want to Update : ";
				cin >> id;
			} while (id < 0);
			editMed(id,arr,Msize);
			break; 
		case 'c': // Delete medicine
			int ID;
			do {
				cout << "Enter ID of Medicine you want to Update : ";
				cin >> ID;
			} while (ID < 0);
			deleteMed(ID, arr, Msize);
			break; 
		case 'd': 	// View Stock
			int iid;
			do {
				cout << "Enter ID of Medicine you want to View : ";
				cin >> iid;
			} while (iid < 0);
			viewMed(iid, arr, Msize);
			break; 
		
		}


	}
	// Manage Supplier 
    else if (option == 2) {

		cout << "----- Manage Supplier -----" << endl;
		cout << "a.Add Supplier " << endl;
		cout << "b.Edit Supplier " << endl;
		cout << "c.Delete Supplier " << endl;
		cout << "d.View Supplier " << endl;
		cout << "--------------------------------" << endl;
		cout << "--------------------------------" << endl;
		char SupplierOption;
		do {
			cout << "Select option : ";
			cin >> SupplierOption;
		} while ((SupplierOption < 'a') || (SupplierOption > 'd'));
		switch (SupplierOption) {
		case 'a': 		// Add medicine
			addSupplier(sArr, Ssize);
			break;
		case 'b':  // Edit medicine
			int id;
			do {
				cout << "Enter ID of Supplier you want to Update : ";
				cin >> id;
			} while (id < 0);
			editSupplier(id, sArr, Ssize);
			break;
		case 'c': // Delete medicine
			int ID;
			do {
				cout << "Enter ID of Supplier you want to Delete : ";
				cin >> ID;
			} while (ID < 0);
			deleteSupplier(ID, sArr, Ssize);
			break;
		case 'd': 	// View Stock
			int iid;
			do {
				cout << "Enter ID of Supplier you want to View : ";
				cin >> iid;
			} while (iid < 0);
			viewSupplier(iid, sArr, Ssize);
			break;

		}


	}
	// Sales 
	else if (option == 3) {
		ofstream salefout("SaleInvoice.txt", ios::app);
		if (!salefout.fail()) {
			string inv;
			cin.ignore();
			cout << "Enter Invoice # : ";
			getline(cin, inv);
			salefout << inv << endl;
			string dat;
			//cin.ignore();
			cout << "Enter Date : ";
			getline(cin, dat);
			salefout << dat << endl;

			int iiid;
			int quan;
			do {
				cout << "Enter id of Medicine : ";
				cin >> iiid;
			} while (iiid < 0);
			salefout << iiid << endl;

			do {
				cout << "Enter Quantity : ";
				cin >> quan;
			} while (quan < 0);
			salefout << quan << endl;
			for (int i = 0; i < Msize; i++) {
				if (arr[i].getID() == iiid) {
					double price=arr[i].getPriceperUnit();
					salefout << price << endl;
					salefout << (price * quan) - (((price * quan )*2)/100) << endl;// Price after Discount
					salefout << (price * quan);//Total Price
					arr[i] - quan;
				}
			}

			salefout.close();
		}
		else
			cout << "\nError in Opening File ...." << endl;
	}
	//Purchase
	else if (option == 4) {
	ofstream Purchasefout("PurchaseInvoice.txt", ios::app);
	if (!Purchasefout.fail()) {
		string inv;
		cin.ignore();
		cout << "Enter Invoice # : ";
		getline(cin, inv);
		Purchasefout << inv << endl;
		string dat;
		//cin.ignore();
		cout << "Enter Date : ";
		getline(cin, dat);
		Purchasefout << dat << endl;

		int iiiD;
		int quant;
		do {
			cout << "Enter id of Supplier: ";
			cin >> iiiD;
		} while (iiiD < 0);
		Purchasefout << iiiD << endl;

		do {
			cout << "Enter Quantity : ";
			cin >> quant;
		} while (quant < 0);
		Purchasefout << quant << endl;
		for (int i = 0; i < Msize; i++) {
			if (arr[i].getID() == iiiD) {
				double price = arr[i].getPriceperUnit();
				Purchasefout << price << endl;
				Purchasefout << (price * quant) - (((price * quant) * 2) / 100) << endl;// Price after Discount
				Purchasefout << (price * quant);//Total Price
				arr[i] + quant;
			}
		}

		Purchasefout.close();
	}
	else
		cout << "\nError in Opening File ...." << endl;
	}
	else if (option == 5) {
		cout << "----- Generate Reports -----" << endl;
		cout << "a.Stock Report " << endl;
		cout << "b.Sales Summary " << endl;
		cout << "c.Purchase Summary " << endl;
		cout << "--------------------------------" << endl;
		cout << "--------------------------------" << endl;
		char reportOption;
		do {
			cout << "Select option : ";
			cin >> reportOption;
		} while ((reportOption < 'a') || (reportOption > 'c'));
		switch (reportOption) {
		case 'a': 		// Stock Report
			//for (int i = 0; i < Msize; i++) {
			//	arr[i].viewStock();
				viewStock(arr,Msize);
			//}
			break;
		case 'b':  // Sale Summary
			//for (int i = 0; i < saleSize; i++) {
				//saleArr[i].viewSaleSummary();
				viewSaleSummary(saleArr,saleSize);
			//}
			break;
		case 'c': // Purchase Summary
			//for (int i = 0; i < purchaseSize; i++) {
				//purchaseArr[i].viewPurchaseSummary();
				viewPurchaseSummary(purchaseArr,purchaseSize);
			//}
			break;

		}
	}
	else if (option == 6) {
		return 1;
	    }
	
	/*cout << "***********" << endl;
	for (int i = 0; i < size; i++) {
		arr[i].viewStock();
	}*/
	 writeFileMed(arr,Msize);
	 writeFileSupplier(sArr,Ssize);
	
	return 0;
}


