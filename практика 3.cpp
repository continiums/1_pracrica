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

struct node
{
	struct record note;
	struct node* next;
};
struct node* myHead;
int countItem = 0;


void additem(const char* name, const char* prod, int count, double cost,date zhaba)
{
	struct node* newitem = new node();
	newitem->note.name = name;
	newitem->note.product = prod;
	newitem->note.count = count;
	newitem->note.cost = cost;
	newitem->note.Date.day = zhaba.day;
	newitem->note.Date.month = zhaba.month;
	newitem->note.Date.year = zhaba.year;
	if (countItem == 0)
	{
		newitem->next = NULL;
	}
	else
	{
		newitem->next = myHead;
	}
	myHead = newitem;
	countItem++;
}
void printitem()
{
	struct node* current = myHead;
	cout << endl;
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
		cout.fill(' ');

	while (current)
	{
		cout << left << "|"; cout.width(13); cout << left << current->note.name;
		cout << left << "|"; cout.width(14); cout << left << current->note.product;
		cout << left << "|"; cout.width(24); cout << left << current->note.count;
		std::cout.precision(2);
		cout << left << "|"; cout.width(8); cout << left << fixed << current->note.cost;
		cout << left << "|";
		drawdate(current->note.Date.day, current->note.Date.month, current->note.Date.year, 11);
		current = current->next;
	}
	cout.width(76); cout.fill('-'); cout << "-" << endl;
	cout << "|"; cout.width(74); cout.fill(' '); cout << left << "примечание: возможно бесплатно получить продукт staroffice через interner"; cout << "|" << endl;
	cout.width(76); cout.fill('-'); cout << "-" << endl << endl;
}
int main()
{
	int indmin, indmax = -10;
	setlocale(LC_ALL, "ru");
	additem("office", "Microsoft", 4, 870.99, { 11,01,2011 });
	additem("smartsute", "lotus", 5, 1020.99, { 21,10,2012 });
	additem("staroffice", "sun", 4, 99, { 21,10,2020 });
	printitem();
}