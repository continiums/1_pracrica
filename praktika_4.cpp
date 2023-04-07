#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct date
{
	int day;
	int month;
	int year;
};
struct record
{
	string name;
	string product;
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


void additem(string name, string prod, int count, double cost, date zhaba)
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

void deleteitem(int index)
{
	if (index >= 0 and countItem > 0 and index < countItem)
	{

		struct node* current = myHead;
		struct node* old;
		if (index == 0)
		{
			old = myHead;
			myHead = current->next;
			delete old;
			countItem--;
		}
		else {
			int i = 0;
			while (current)
			{
				if (i == index - 1) {
					old = current->next->next;
					delete current->next;
					current->next = old;
					countItem--;
					break;
				}
				current = current->next;
				i++;
			}

		}
	}
}
void insertitem(int index, record note)
{
	if (not (index >= 0 and index <= countItem and countItem >= 0)) return;
	if (index == 0) {
		additem(note.name, note.product, note.cost,note.cost,note.Date);
	}
	else {
		struct node* current = myHead;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		struct node* newItem = new node();
		newItem->note = note;
		newItem->next = current->next;
		current->next = newItem;
		countItem++;
	}
}

int main()
{
	setlocale (LC_ALL, "ru");
	struct record records[4] = { "office","Microsoft",4,870.99,{11,01,2011,},
	   "smartsute","lotus",5,1020.99,{21,10,2012},
	   "staroffice","sun",4,99,{21,10,2020} };
	ifstream intt;
	ofstream outb;
	ofstream outt("AT", ios_base::out);
	outb.open("AB", ios_base::out | ios_base::binary);
	char a[] = "\n123\n";
	cout << sizeof(records) << "\n";
	for (int i = 0; i < 3; i++)
	{
		outb << " " << records[i].name << " " << records[i].product << " " << records[i].count << ' ' << records[i].cost << ' ' << records[i].Date.day << ' ' << records[i].Date.month << ' ' << records[i].Date.year << endl;
		outt << " " << records[i].name << " " << records[i].product << " " << records[i].count << ' ' << records[i].cost << ' ' << records[i].Date.day << ' ' << records[i].Date.month << ' ' << records[i].Date.year << endl;
	}
	outt.close();
	record out[4];
	intt.open("AT", ios_base::in);
	for (int i = 0; !intt.eof(); i++)
	{
		intt >> out[i].name >> out[i].product >> out[i].count >> out[i].cost >> out[i].Date.day >> out[i].Date.month >> out[i].Date.year;
	}
	additem(out[0].name, out[0].product, out[0].count, out[0].cost, out[0].Date);
	additem(out[1].name, out[1].product, out[1].count, out[1].cost, out[1].Date);
	additem(out[2].name, out[2].product, out[2].count, out[2].cost, out[2].Date);
	printitem();
	intt.close();
	cout << endl <<  "второй этап";
	ofstream outtt;
	outtt.open("AT",ofstream::app);
	out[3] = { "geralt", "CD project red",1, 7000, {2, 7, 2004 } };
	outtt << " " << out[3].name << " " << out[3].product << " " << out[3].count << ' ' << out[3].cost << ' ' << out[3].Date.day << ' ' << out[3].Date.month << ' ' << out[3].Date.year << endl;
	outtt.close();
	additem(out[3].name, out[3].product, out[3].count, out[3].cost, out[3].Date);
	printitem();
	record temp = out[0];
	deleteitem(3);
	//printitem();
	insertitem(1, temp);
	//printitem();
	temp = out[2];
	deleteitem(2);
	//printitem();
	cout << "поменять 2 и 4 строки местами:" << endl;
	insertitem(3, temp);
	printitem();
}