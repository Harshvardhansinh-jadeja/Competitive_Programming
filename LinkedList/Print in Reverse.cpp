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

    void print()
    {
        node *temp = first;
        while (temp != NULL)
        {
            cout << temp->data << endl;

            temp = temp->link;
        }
    }
    void reverse()
    {
        node *pre, *curr, *next;
        pre = NULL;
        curr = first;
        next = NULL;
        while (curr != NULL)
        {
            next = curr->link;
            curr->link = pre;
            pre = curr;
            curr = next;
        }
        first = pre; //To start the node at the end.
    }
    void deleteNode()
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
        i1.reverse();
        i1.print();
        i1.deleteNode();
    }

    return 0;
}
