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
    void print()
    {
        node *temp = first;
        while (temp != NULL)
        {
            cout << temp->data;
            cout << " ";
            temp = temp->next;
        }
    }
    void insertInSorted(int x)
    {
        node *temp = first;
        // cout<<temp->data<<" "<<x<<endl;
        while (temp->data < x && temp->next != NULL)
        {
            temp = temp->next;
        }
        // cout << temp->data;
        node *nn = new node(x);
        if (temp == first)
        {
            nn->next = first;
            nn->prev = NULL;
            first->prev = nn;
            first = nn;
        }
        else if (temp->next == NULL)
        {
            if (temp->data < x)
            {
                //Insert After TEMP
               nn->next= NULL;
               temp->next = nn;
               nn->prev = temp;
                
            }
            else
            {
                //Insert Before Temp
                nn->prev = temp->prev;
                nn->next = temp;
                temp->prev->next = nn;
                temp->prev = nn;
            }
      
        }
        else
        {
            nn->next = temp;
            nn->prev = temp->prev;
            temp->prev->next = nn;
            temp->prev = nn;
        }
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

    void reverse_print()
    {
        node *temp = first;
        if (temp == NULL)
        {
            return;
        }
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        while (temp != NULL)
        {
            cout << temp->data;
            cout << " ";
            temp = temp->prev;
        }
    }
    void nulldo()
    {
        first = NULL;
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
            // i1.insert_before(j);
        }
        int j;
        cin >> j;
        i1.insertInSorted(j);
        i1.print();
        i1.nulldo();
        // int TailPosition;
        // cin >> TailPosition;
        // i1.getNodeValue(TailPosition);
        // i1.reverse_print();
        cout << endl;
        // i1.deleteNode();
    }
    return 0;
}
