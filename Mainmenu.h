//#include"MenuDish.h"
//#include"Dish.h"
#include"Restoraunt.h"
void rabotasklientom(MenuDish& p);
void rabotasmenu(MenuDish& p);
void mainMenu()
{
	Restoraunt p;
	MenuDish* md_ptr=  &p;
	setlocale(LC_ALL, "rus");	
	cout << "Добро пожаловать в программу ресторан.\n Нажмите ENTER для прдолжения: \n";
	int vibor;
	cin.clear();
	do{

		cin.ignore();
		cin.clear();
		cout << "Вам доступны следущие функции: \n";
		cout << "1 Работа с клиентом. ";
		cout << endl;
		cout << "2. Работа с меню.  (загрузка,редактирование,сохранение)";
		cout << endl;
		//cout << "3 Показ сделаных   заказов. ";
		//cout << endl;
		cout << "0 Выход из программы. ";
		cout << endl;
		cout << "Выберете номер доступной функци. \n";
		cin >> vibor;
		switch (vibor)
		{
		case 1:
		{	rabotasklientom(*md_ptr);
		
		break;
		}
		case 2:
		{	rabotasmenu(*md_ptr);

		break;
		}
	
		case 0:
			break;

		default:
			vibor = 100;
			cin.clear();
			continue;
	
		}

	} while (vibor > 0);






}
void rabotasklientom(MenuDish& md_ptr)
{
	setlocale(LC_ALL ,"rus");
	cout << "Вы находитесь в разеле : Работа с клиентом. \n";
	//cin.clear();
	//cin.ignore();
	int vibor;
	do{
		cin.clear();
		cin.ignore();
		cout << "Вам доступны следущие функции: \n";
		cout << "1 Показ текущего  меню на Экран. " << endl;
		
		cout << "2. Принять заказ.  " << endl;
		cout << "3 Показ сделаных   заказов. " << endl;
		cout << "0 для выхода. " << endl;
		//cout << "4. редактировать заказ. \n";
		cout << "Выберете номер доступной функци.\n";
		cin >> vibor;
		if (cin.good())
			vibor = vibor;	//continue;
		else
		{
			vibor = 0;
			cin.clear();
		}
		
			switch (vibor)
			{
			case 1:
			{	md_ptr.show();
			break;
			}
			case 2:
			{	md_ptr.makeOrder();
			break;
			}
			case 3:
			{	md_ptr.showAllOrders();
			break;
			}

			default:
				break;
			}

		
	//	else vibor = 0;

	} while (vibor > 0 );

}
void rabotasmenu(MenuDish& p)

{
	cout << "Вы находитесь в разеле : Работа с меню. \n";
	//cin.clear();
	int vibor;
	do{
		cin.clear();
		cin.ignore();
		cout << "Вам доступны следущие функции: \n" << endl;;
		cout << "1 Показать текущее меню на экран. " << endl;;
		cout << "2 добавление блюда в меню. " << endl;;
		cout << "3 Удаление блюда из меню. " << endl;;
		cout << "4 Сохранить Меню. " << endl;;
		cout << "5 Загрузить новое меню. " << endl;; 
		cout << "6 редактировать блюдо. " << endl;
		cout << "0 для выхода. " << endl;
		cout << "Выберете номер доступной функци.\n";


		cin >> vibor;
		switch (vibor)
		{
		case 1:
		{	p.showMenu();
		break;
		}
		case 2:
		{	p.addDish();
				  break;
		}
		case 3:
		{	p.deleteDish();
				  break;

		}
		case 4:
		{	p.saveInFile();
		break;
		}
		case 5:
		{
			p.lodFromFile();
		break;
		}
		case 6:
		{
				  int ind;
				  p.show();
				  cout << "Введите индекс блюда для редактирования: " ;
				  cin >> ind;
				  cout << endl;
				  cout << "Что редактировать?  1=название блюда.   2=цена блюда.   3=тип блюда. " << endl;
				  int vibor;
				  cin >> vibor;
				  switch (vibor)
				  {
					  cin.ignore();
				  case 1:p.menu[ind-1].editTitle();
					  break;
				  case 2:p.menu[ind-1].editPrice();
					  break;
				  case 3:p.menu[ind-1].editType();
					  break;
				  default:
					  break;
				  }

				  
				  break;
		}


		default:
			break;
		}

	} while (vibor > 0);


}

