#include <iostream>
#include<string>
#include<string.h>
#include<vector>
#include<iomanip>
using namespace std;

#pragma once
enum type_dish{ cold=1, hot, desert,untyped };
class Dish
{
public:
	string title;
	double price;
	type_dish type;
public:

	Dish operator +( int i)
	{
		this->price += i;
		return *this;
	}
	Dish operator -(int i)
	{
		this->price -= i;
		return *this;
	}
	operator double(){ return this->price; }
	friend ostream & operator << (ostream & os,const Dish obj )
	{
		os <<"Name   "<<obj. title << endl;
		os <<"Price  "<< obj.price << endl;
		
		switch (obj.type)
		{case cold:
			os << "Cold dish. \n";
				break;
		case hot:
			os << "Hot dish.\n ";
			break;
		case desert:
			os << "Desert. \n";
			break;
		case untyped:
			os << "Untyped. \n";
			break;
		default:
			break;
		}
		//os << endl;
		return os;
	}
	
	
	//////////////////////////////
	 void editTitle();
	 void editPrice();
	 void editType();
	 void editDish();
	 string printType();
	//////////////////////////
	Dish getDish();
	string getTitle();
	double getPrice();
	type_dish getType();
	string pbTitle(string);
	string o0Title(string);
	/////////////////////////////////
	bool equTitle(string);
	bool equPrice(double);
	bool equType(type_dish);
//////////////////////////
	void setAll();
	void setTitle(string);
	void setPrice(double);
	void setType(type_dish);
	void setType(string);
	//////////////////////////
	Dish(string , double , type_dish );
	Dish(const Dish &);
	Dish();
	~Dish();
};

