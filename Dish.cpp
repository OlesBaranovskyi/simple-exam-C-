#include "Dish.h"


void Dish::editDish()
{
	editTitle();
	editPrice();
	cin.get();
	editType();
	cin.get();
}
 void Dish::editTitle()
{
	string tempTitle;
	cout << "Please enter the  title of dish : ";
	cin.ignore();
	getline(cin,tempTitle);
	setTitle(tempTitle);

}
 void Dish::editPrice()
 {
	 double tempPrice;
	 cout << "Please enter the  price of dish : ";
	 cin >> tempPrice;

		setPrice(tempPrice);
		
 }
 void Dish::editType()
 {

	type_dish tempType;
	
	
	int vibor;
	cout << "Enter the type of dish 1=cold, 2 = hot, 3=desert \n";
	cin>> vibor;
	switch (vibor)
	{
	case 1:
		setType(cold);
		break;
	case 2:
		setType(hot);
		break;
	case 3:
		setType(desert);
		break;
	default:
		break;
	}

 }
//////////////////////////////////////
 Dish Dish::getDish()
 {
	
	 return *this;
 }
type_dish Dish::getType()
{
	return type;
}
double Dish::getPrice()
{
	return price;
}
string Dish::getTitle()
{
	
	return title;
}
string Dish::pbTitle(string tit)
{
	string tnpstr = tit;
	for (int i = 0; i< tnpstr.size(); i++)
	{
		if (tnpstr[i] == '0')
			tnpstr[i] = ' ';

	}
	return tnpstr;
}
string Dish::o0Title(string tit)
{
	string str = tit;
	for (int i = 0; i< tit.size(); i++)
    {
	if (str[i] == ' ')
		str[i] = '0';

    }
	return str;
}
/////////////////////////////////////
void Dish::setAll()
{
	string t;
	double p; 
	type_dish ty;
	cout << "Enter title of dish: \n";
	getline(cin, t);
	this->setTitle(t);
	//cin.get();
	
	cout << "Enter price of dish: \n";
	cin >> p;
	//cin.get();
	this->setPrice(p);
	


	int vibor;
	cout << "Enter the type of dish 1=cold, 2 = hot, 3=desert , \n";
	cin >> vibor;
	
	switch (vibor)
	{
	case 1:
		this->setType(cold);
		break;
	case 2:
		this->setType(hot);
		break;
	case 3:
		this->setType(desert);
		break;
	default:
		break;
	}
	cin.get();
}
void Dish::setPrice(double p)
{
	
	if (p>0)
	price = p;
	
	else price = 0.1;
	
}
void Dish::setTitle(string t)
{
	
	if (t.size() < 60 && t.size())
	{
		title = t;
	}
	
}
void Dish::setType(type_dish t)
{
	if (t == cold || t == hot || t == desert||t==untyped) {type = t;}
	else
	{
		return;
	}

}

void Dish::setType(string type)
{
	if (type == "1")setType(cold);
	if (type == "2")setType(hot);
	if (type == "3")setType(desert);
	if (type == "untyped")setType(untyped);
	else return;
}

///////////////////////////////////////

string Dish::printType()
{
	switch (type)
	{
	case cold:
		/*cout*/return "Cold dish.";
		//break;
	case hot:
		return "Hot dish. ";
		//break;
	case desert:
		return "Desert.";
		//break;
	case untyped:
		return "Untyped.";
		//break;
	default:
		break;
	}
}
bool Dish::equPrice(double _price)
{
	if (price == _price)return true;
	return false;

}
bool Dish::equTitle(string _Title)
{
	if (title == _Title)return true;
	return false;
}
bool Dish::equType(type_dish t)
{
	if (type == t)return true;
	return false;
}


Dish::Dish(string t, double p, type_dish ty)
{
	setTitle(t);
	setPrice(p);
	setType(ty);
	
}
Dish::Dish(const Dish &obj)
{
	title = obj.title;
	price = obj.price;
	type = obj.type;


}
Dish::Dish()
{
	title = "Dish";
	price = 0;
type = untyped;

}
Dish::~Dish()
{
}
