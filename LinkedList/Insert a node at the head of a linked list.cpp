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
    void insert_before(int d)
    {
        if (first == NULL)
        {
            node *nn = new node(d);
            first = nn;
        }
        else
        {
            node *nn = new node(d);
            nn->link = first->link;
            first->link = nn;
        }
    }
    void print()
    {
        node *temp = first->link;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->link;
        }
        //just for one time
        cout << first->data;
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
        i1.insert_before(j);
    }

    i1.print();

    return 0;
}
