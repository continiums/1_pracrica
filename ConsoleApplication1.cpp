#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};
struct node* myHead;
int countItem = 0;

void additem(int data)
{
    struct node* newitem = new node();
    newitem->data = data;
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
    while (current)
    {
        cout << "  " << current->data;
        current = current->next;
    }
}

void edititem(int index, int data)
{
    struct node* current = myHead;
    if (index >= 0 and index < countItem and countItem > 0)
    {
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        current->data = data;
    }
    else
    {
        cout << "ошибка ввода индекса";
    }
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
void insertitem(int index, int data)
{
    if (not (index >= 0 and index <= countItem and countItem >= 0)) return;
    if (index == 0) {
        additem(data);
    }
    else {
        struct node* current = myHead;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        struct node* newItem = new node();
        newItem->data = data;
        newItem->next = current->next;
        current->next = newItem;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    additem(1);
    additem(2);
    printitem();
    //edititem(2, 8);
    //deleteitem(2);
    insertitem(2, 8);
    printitem();
}