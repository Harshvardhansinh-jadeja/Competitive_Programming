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

    void deleteDupli()
    {
        node *temp = first;
        while (temp->link != NULL)
        {
            if (temp->data == temp->link->data)
            {
                if (temp->link->link == NULL)
                {
                    temp->link = NULL;
                    return;
                }
                temp->link = temp->link->link;
            }
            else
            {
                temp = temp->link;
            }
        }
    }

    void print()
    {
        node *temp = first;
        while (temp != NULL)
        {
            cout << temp->data;
            cout << " ";
            temp = temp->link;
        }
    }
    void deleteNode()
    {
        first = NULL;
    }

    void null_data()
    {
        first = NULL;
    }
};

int main()
{
    Imple i1;

    // cout<<"How many elements you want to enter into the linked list"<<endl;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int j;
            cin >> j;
            i1.insert(j);
        }
        i1.deleteDupli();
        i1.print();
        cout << endl;
        i1.null_data();
    }

    return 0;
}
