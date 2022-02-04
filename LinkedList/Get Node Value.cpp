#include <iostream>
using namespace std;

class node
{
private:
    node *prev;
    long long int data;
    node *next;

public:
    node(long long int d)
    {
        data = d;
        prev = next = NULL;
    }
    friend class Imple;
};

class Imple
{
public:
    node *first;
    Imple()
    {
        first = NULL;
    }

    void insert(long long int x)
    {
        if (first == NULL)
        {
            node *nn = new node(x);
            first = nn;
        }
        else
        {
            node *temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            node *nn = new node(x);
            temp->next = nn;
            nn->prev = temp;
        }
    }

    void deleteNode()
    {
        first = NULL;
    }

    void getNodeValue(int TailPosition)
    {
        node *temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        for (int i = 0; i < TailPosition; i++)
        {
            temp = temp->prev;
        }
        cout << temp->data;
    }
};

int main()
{
    Imple i1;

    // cout<<"How many elements you want to enter into the linked list"<<endl;
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        for (long long int i = 0; i < n; i++)
        {
            long long int j;
            cin >> j;
            i1.insert(j);
        }
        int TailPosition;
        cin >> TailPosition;
        i1.getNodeValue(TailPosition);
        cout << endl;
        i1.deleteNode();
    }
    return 0;
}
