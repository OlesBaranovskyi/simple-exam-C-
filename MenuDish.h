#pragma once
#include"Dish.h"
#include<ostream>
#include<istream>
#include<fstream>
#include<map>
#include<algorithm>
#include<cstdio>
class MenuDish
{
public:
	  vector< Dish> menu;
	  double invoice;
public:
	void setInvoice();
	double getInvoice();
	void lodFromFile();
	void saveInFile();
	void saveInFile(string);
	Dish &findDishTitle();
	void findDishType();
	void findPrice();
	virtual void showMenu();
	
	 virtual void show();
	 void deleteDish();
	 void editDish();
	 virtual void makeOrder()
	 {}
	 virtual void showOrder()
	 {}
	 virtual void showAllOrders(){}
	 virtual void addDish();
	 virtual void addDish(Dish);
	MenuDish();
	MenuDish(const MenuDish &);
	~MenuDish();
};

