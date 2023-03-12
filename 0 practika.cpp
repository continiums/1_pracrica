#include <iostream>
#include <windows.h>
#include <string>
#include <iomanip>

using namespace std;
struct date
{
	int day;
	int month;
	int year;
};
struct record
{
	const char* name;
	const char* product;
	int count;
	double cost;
	date Date;
};

void drawdate(int day, int month, int year, int wline)
{
	int w = 10;
	int delta = (wline - w);
	cout.width(delta); cout << " ";
	cout << left;
	if (day > 9) cout << day;
	else cout << "0" << day;
	cout << ".";
	if (month > 9) cout << month;
	else cout << "0" << month;
	cout << ".";
	cout << year << "|" << endl;
}

void draw(struct record* records)
{

	cout.width(76); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(75); cout << left << "|офисные пакеты"; cout << "|" << endl;
	cout.width(76); cout.fill('-'); cout << "-" << endl;
	cout << left << "|наименование ";
	cout << left << "|производитель ";
	cout << left << "|количество сост. частей ";
	cout << left << "|цена($) ";
	cout << left << "|дата релиза";
	cout << "|" << endl;
	cout.width(76); cout.fill('-'); cout << "-" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout.fill(' ');
		cout << left << "|"; cout.width(13); cout << left << records[i].name;
		cout << left << "|"; cout.width(14); cout << left << records[i].product;
		cout << left << "|"; cout.width(24); cout << left << records[i].count;
		std::cout.precision(2);
		cout << left << "|"; cout.width(8); cout << left << fixed << records[i].cost;
		cout << left << "|";
		drawdate(records[i].Date.day, records[i].Date.month, records[i].Date.year, 11);
	}
	cout.width(76); cout.fill('-'); cout << "-" << endl;
	cout << "|"; cout.width(74); cout.fill(' '); cout << left << "примечание: возможно бесплатно получить продукт staroffice через interner"; cout << "|" << endl;
	cout.width(76); cout.fill('-'); cout << "-" << endl << endl;
}


int main()
{
	int indmin, indmax = -10;
	setlocale(LC_ALL, "ru");
	struct record records[10];
	records[0] = { "office","Microsoft",4,870.99,{11,01,2011} };
	records[1] = { "smartsute","lotus",5,1020.99,{21,10,2012} };
	records[2] = { "staroffice","sun",4,99,{21,10,2020} };



	draw(records);
}