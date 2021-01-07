// lab8.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//
#include "stdafx.h"


#include"File.h"

using namespace std;
int main()
{
	Student t1("Zhuk_Artem_Yurievich", 751901, 10, 612);
	Student t2("Ignatovich_Konstantin_Sergeevich", 832002, 4, 322);
	Student t3("Latushko_Svetlana_Sergeevna", 675103, 9, 751);
	Student t4("Daroshevish_Ira_Davydovna", 920951, 5, 834);
	Student t5("Cheh_Petr_Dmitrievich", 950507, 4, 305);
	Student un[5] = { t1,t2,t3,t4,t5 };
	cout << "\n-------TXT in TXT mode-------\n";
	File f1("1.txt", txt);
	f1.open("w");
	f1.set_size(5);
	f1 << t1;
	f1 << t2;
	f1 << t3;
	f1 << t4;
	f1 << t5;
	f1.close();
	f1.open("r");
	cout << f1;
	f1.close();
	int i = 0, line = 0;
	cout << "\n--------------------------------------------------------\n";
	cout << "Sort by fio:" << endl;
	cout << "\n--------------------------------------------------------\n";
	f1.bouble_sort_fio();
	f1.open("r");
	cout << f1;
	f1.close();
	cout << "\n--------------------------------------------------------\n";
	cout << "Sort by number of groups:" << endl;
	cout << "\n--------------------------------------------------------\n";
	f1.bouble_sort_groups();
	f1.open("r");
	cout << f1;
	f1.close();
}