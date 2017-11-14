#pragma once
#include "MenuDish.h"
#include"Menu.h"
class Restoraunt:
	public MenuDish
{
	
public:
	vector< MenuDish> zakazi;
	double allmoney;


public:

	double getAllMoney();
	void showOrder(int i)
	{
		cout << "Restoraunt¹" << i<<"."<<endl;
		zakazi[i].show();

	}
	void showOrder();
	
	void showAllOrders();
	
	virtual void makeOrder();
	virtual void Invoice();
	Restoraunt();
	~Restoraunt();
};

