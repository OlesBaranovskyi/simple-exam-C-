#include "Restoraunt.h"

void Restoraunt::makeOrder()
{

	int ind;
	MenuDish z;
	showMenu();
	do
	{
		z.setInvoice();
		cout << "\n В заказе " << z.menu.size() <<" блюда на  "<<z.getInvoice()<<" гривен."<< endl;
		cout << "Enter index of dish for add in order.  Or push 0 for close order.  Or -1 for cancel order. \n  ";

		cin >> ind;
		if (ind < 0)
		{
			cout << "Order canceled.\n";
			return;
		}
		if (ind == 0)
		{
			string nameFile = "Invoices.txt";
			z.saveInFile(nameFile);
			break;
		}
		if (ind >menu.size())break;
		z.addDish(menu[ind-1]);
		
		
	} while (ind != 0);
	if (z.menu.size())
	{
		zakazi.push_back(z);
		//zakazi[0].setInvoice();
	}
}
double Restoraunt::getAllMoney()
{
	return allmoney;
}
void Restoraunt::showAllOrders()
{
	allmoney = 0;
	for (int i = 0; i < zakazi.size(); ++i)
	{
		
		zakazi[i].setInvoice();
		allmoney += zakazi[i].getInvoice();
	}


	for (int i = 0; i < zakazi.size(); ++i)
	{
		cout << "zakaz nomer :" << i+1 << endl;
		//zakazi[i].setInvoice();
		zakazi[i].show();
		cout << "\n K oplate : " << zakazi[i].getInvoice() << endl;;
	}

	cout << "------------------------------" << endl;
	cout << "Всего заплпчено : " << getAllMoney()<<endl;

}
void Restoraunt::showOrder()
{
	int ind;
	cout << "Enter the number of order for show:";
	do
	{
		cin >> ind;
	} while (ind >= zakazi.size() || ind < 0);
	
	
	
	
	showOrder(ind);


}

void Restoraunt::Invoice()
{
	double invoice;

	


}

Restoraunt::Restoraunt()
{

}


Restoraunt::~Restoraunt()
{
}
