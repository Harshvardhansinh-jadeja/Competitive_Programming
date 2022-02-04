#include <iostream>
using namespace std;

class node
{
private:
    node *link;
    int data;
    friend class Imple;

public:
    node(int d)
    {
        data = d;
        link = NULL;
    }
};

class Imple
{
private:
    node *first;

public:
    Imple()
    {
        first = NULL;
    }
    void insert(int d)
    {
        if (first == NULL)
        {
            node *n1 = new node(d);
            first = n1;
        }
        else
        {
            node *temp = first;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            node *nn = new node(d);
            temp->link = nn;
        }
    }

    void deleteAtPosition(int p)
    {
        node *temp = first;
        if (p == 0)
        {
            first = temp->link;
        }
        for (int i = 1; i < p; i++)
        {
            temp = temp->link;
        }
        temp->link = temp->link->link;
    }

    void print()
    {
        // node *temp = first->link;
        node *temp = first;
        while (temp != NULL)
        {
            cout << temp->data;
            cout << " ";
            temp = temp->link;
        }
    }
};

int main()
{
    Imple i1;

    // cout<<"How many elements you want to enter into the linked list"<<endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin >> j;
        i1.insert(j);
    }
    int number, position;
    cin >> position;
    i1.deleteAtPosition(position);
    i1.print();

    return 0;
}
