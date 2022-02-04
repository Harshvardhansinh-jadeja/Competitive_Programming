#include <iostream>
using namespace std;

class node
{
public:
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
    node *getAdd()
    {
        return first;
    }

    void null_data()
    {
        first = NULL;
    }

    void compare(node *t1)
    {
        node *temp = first;
        while (temp != NULL && t1 != NULL)
        {
            if (temp->data != t1->data)
            {
                cout << "0" << endl;
                return;
            }
            temp = temp->link;
            t1 = t1->link;
        }
        if (temp == NULL && t1 == NULL)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
};

int main()
{
    Imple i1, i2;

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
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int j;
            cin >> j;
            i2.insert(j);
        }

        node *t1 = i2.getAdd();
        i1.compare(t1);
        i1.null_data();
        i2.null_data();
    }

    return 0;
}
