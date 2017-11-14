#include "MenuDish.h"
void MenuDish::saveInFile()
{
	
	//string fileName;
	string nameFile;
	int vibor;
	cout << "wich menu you want save!" << endl;
	cout << "1=breakfast menu.   2=Lunch menu.  3=Dinner menu" << endl;
	cin >> vibor;
	switch (vibor)
	{
	case 1:
		nameFile = "menuutro.txt";
		break;
	case 2:
		nameFile = "menu1.txt";
		break;
	case 3:
		nameFile = "menuvecher.txt";
		break;

	default:
		break;
	}

	ofstream fout;
	fout.open( nameFile);
	if (!fout) { cout << "Eror culd not save file.\n"; return ; }

	for (int it = 0; it < menu.size(); ++it)
	{
	fout << menu[it].o0Title(menu[it].getTitle()) << "             "
			<< menu[it].getPrice() <<"                 "<< menu[it].getType() << endl;

	}
	
	fout.close();
}
void MenuDish::saveInFile(string nameFile)
{
	setInvoice();
	ofstream fout;
	fout.open(nameFile,ios::app);
	if (!fout) { cout << "Eror culd not save file.\n"; return; }
	fout << "__________________________________________________\n";
	for (int i = 0; i < menu.size(); ++i)
	{
		fout << "| " << i + 1 << " | " << left << setw(27) << menu[i].getTitle() << "  |  ";
		fout << setw(13) << menu[i].printType()<<" | ";
		
		fout << setprecision(4) << right << menu[i].getPrice() << /*setfill('0') <<*/endl;


	}
	fout << "--------------------------------------------------\n";
	fout <<"К оплате :"<< getInvoice()<<endl;
	fout << "__________________________________________________\n";
	fout << endl;
	fout.close();


}
void MenuDish::lodFromFile()
{
	menu.clear();
	string nameFile;
	int vibor;
	cout << "wich menu you want load!" << endl;
	cout << "1=breakfast menu.   2=Lunch menu.  3=Dinner menu" << endl;
	cin >> vibor;
	switch (vibor)
	{
	case 1:
		nameFile = "menuutro.txt";
		break;
	case 2:
		nameFile = "menu1.txt";
		break;
	case 3:

		nameFile = "menuvecher.txt";
		break;
	default:
		cin.clear();
		vibor = 0;
		return;
		//break;
	}


	
	Dish tmp;
	string tit;
	double prc;

	string type;
	ifstream fin(nameFile);	
	map <string,Dish> mapmenu;
	while (!fin.eof())
	{
		
		fin >> tit >> prc >> type;
		tmp.setTitle(tmp.pbTitle(tit));
		tmp.setPrice(prc);
		tmp.setType(type);
		mapmenu.insert(make_pair(tmp.getTitle(), tmp.getDish()));

	}
	auto it = mapmenu.begin();
	for (; it != mapmenu.end(); ++it)
	{
		menu.push_back(it->second.getDish());
	}
	setInvoice();
}
Dish &MenuDish::findDishTitle()
{
	Dish *dptr = NULL;
	string fnd;
	cout << "Enter Title to find dish : ";
	
	getline(cin, fnd);
	
	for (int i = 0; i < menu.size(); ++i)
	{
		if (menu[i].getTitle() == fnd)
			return menu[i];
	}
	cout << "Dish not found.\n";
	
}
void MenuDish::findDishType()
{
	type_dish tempType;
	

	int vibor;
	cout << "Enter the type of dish 1=cold, 2 = hot, 3=desert \n";
	cin >> vibor;
	switch (vibor)
	{
	case 1:
		tempType=cold;
		break;
	case 2:
		tempType=hot;
		break;
	case 3:
		tempType=desert;
		break;
	default:
		
		return;
	}
	multimap<string, Dish> mp;
	auto it = menu.begin();
	for (int i = 0; i < menu.size();++i)
	{
		if (menu[i].equType(tempType))
		{
			pair<string, Dish>p(menu[i].getTitle(), menu[i].getDish());
			mp.insert(p);

		}
		
	}

	if (!mp.size())
		cout << "No find dish \n";


	else
		cout << "In ower menu we find next dish. \n";
	cout << left << setw(16) << "Dish" << setw(13) << " Type" << setw(6) << "Price \n\n";
	
	for (auto i = mp.begin(); i != mp.end(); i++)
	{
		cout << left << setw(17) << i->second.pbTitle(i->second.getTitle());
		cout << setw(13) << i->second.printType();	cout << setw(4) << setprecision(4);
		cout << i->second.getPrice() << endl;
		cout << "__________________________________________________\n";
		
		cout << endl;
	}

}
void MenuDish::findPrice()
{
	
	double fndprc;
	cout << "Enter price for find. \n";
	cin >> fndprc;
	fndprc<0 || fndprc>1000 ? fndprc = 0 : fndprc = fndprc;
	multimap<string, Dish> tmp;
	for (int it = 0; it <menu.size(); ++it)
	{
		if (menu[it].getPrice() == fndprc)
		{
			pair<string, Dish>p(menu[it].getTitle(), menu[it].getDish());
			tmp.insert(p);
		}
	}

	if (!tmp.size())
		cout << "No find dish \n";


	else
		cout << "In ower menu we find next dish. \n";
	cout << left << setw(16) << "Dish" << setw(13) << " Type" << setw(6) << "Price \n\n";

	for (auto i = tmp.begin(); i != tmp.end(); i++)
	{
		cout << left << setw(17) << i->second.pbTitle(i->second.getTitle());
		cout << setw(13) << i->second.printType();	cout << setw(4) << setprecision(2);
		cout << i->second.getPrice() << endl;
		cout << "__________________________________________________\n";
		
		cout << endl;
	}
}
void MenuDish::deleteDish()
{
	
	int ind;
	cout << "Enter index of dish for delete.\n";
	cin >> ind;
	if (ind>=0||ind<=menu.size())
	{
		menu.erase(menu.begin() + ind-1);
			cout << "Delete sucessed.\n";
		return;
	}
	cout << "Delete eror!\n";

}
void MenuDish::addDish()
{
	Dish newDish;
	getchar();
	newDish.setAll();
	menu.push_back(newDish);
	
}
void MenuDish::addDish(Dish d)
{
	menu.push_back(d);


}
void MenuDish::editDish()
{
	cout << "Wich dish you want to edit? enter title :";
	string fnd;
	getline(cin, fnd);
	cout << endl;
	for (int i = 0; i < menu.size(); ++i)
	{
		if (menu[i].getTitle() == fnd)
		{
			menu[i].editDish();
			cout << "Editing sucessed.\n";
			return;
		}
	}
	
		cout << "Eror edit! Dish not found \n";
		return;
	
}
void MenuDish::setInvoice()
{
	double tmp=0;
	for (int i = 0; i < menu.size(); ++i)
	{
		tmp += menu[i].getPrice();
	}

	invoice = tmp;
}
double MenuDish::getInvoice()
{
	return invoice;
}
void MenuDish::showMenu()
{
	if (!menu.size())
	{
		cout << "Menu empty! \n";
		return;
	}
	else
		cout << "In ower restoraunt you can by next Dish \n";
	cout << left << setw(16) << "Dish" << setw(13) << " Type" << setw(6) << "Price \n\n";

	show();

}
void MenuDish::show()
{
	
	for (int i=0; i<menu.size() ; i++)
	{
		cout << "| " << i + 1 << " | " << left << setw(27) << menu[i].getTitle()<<"  |  ";
		cout << setw(13) << menu[i].printType();	
		//cout << setw(5) << setprecision(4);
		cout << setprecision(4)<<right << menu[i].getPrice() << /*setfill('0') <<*/endl;
		cout <<  "__________________________________________________\n";
		
	}

}
MenuDish::MenuDish()
{
	
}

MenuDish::MenuDish(const MenuDish &obj)
{
	menu = obj.menu;
}
MenuDish::~MenuDish()
{
}
