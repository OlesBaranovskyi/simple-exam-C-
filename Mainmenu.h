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
	cout << "����� ���������� � ��������� ��������.\n ������� ENTER ��� ����������: \n";
	int vibor;
	cin.clear();
	do{

		cin.ignore();
		cin.clear();
		cout << "��� �������� �������� �������: \n";
		cout << "1 ������ � ��������. ";
		cout << endl;
		cout << "2. ������ � ����.  (��������,��������������,����������)";
		cout << endl;
		//cout << "3 ����� ��������   �������. ";
		//cout << endl;
		cout << "0 ����� �� ���������. ";
		cout << endl;
		cout << "�������� ����� ��������� ������. \n";
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
	cout << "�� ���������� � ������ : ������ � ��������. \n";
	//cin.clear();
	//cin.ignore();
	int vibor;
	do{
		cin.clear();
		cin.ignore();
		cout << "��� �������� �������� �������: \n";
		cout << "1 ����� ��������  ���� �� �����. " << endl;
		
		cout << "2. ������� �����.  " << endl;
		cout << "3 ����� ��������   �������. " << endl;
		cout << "0 ��� ������. " << endl;
		//cout << "4. ������������� �����. \n";
		cout << "�������� ����� ��������� ������.\n";
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
	cout << "�� ���������� � ������ : ������ � ����. \n";
	//cin.clear();
	int vibor;
	do{
		cin.clear();
		cin.ignore();
		cout << "��� �������� �������� �������: \n" << endl;;
		cout << "1 �������� ������� ���� �� �����. " << endl;;
		cout << "2 ���������� ����� � ����. " << endl;;
		cout << "3 �������� ����� �� ����. " << endl;;
		cout << "4 ��������� ����. " << endl;;
		cout << "5 ��������� ����� ����. " << endl;; 
		cout << "6 ������������� �����. " << endl;
		cout << "0 ��� ������. " << endl;
		cout << "�������� ����� ��������� ������.\n";


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
				  cout << "������� ������ ����� ��� ��������������: " ;
				  cin >> ind;
				  cout << endl;
				  cout << "��� �������������?  1=�������� �����.   2=���� �����.   3=��� �����. " << endl;
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

