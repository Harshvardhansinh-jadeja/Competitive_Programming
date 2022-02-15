#include <bits/stdc++.h>
using namespace std;

class node
{
private:
    int data;
    node *LChild;
    node *RChild;

public:
    node(int d)
    {
        data = d;
        LChild = NULL;
        RChild = NULL;
    }
    friend class Tree;
};
node *root = NULL;
class Tree
{
public:
    void insert(int key)
    {
        node *p, *t, *r;
        r = root;
        if (r == NULL)
        {
            p = new node(key);
            root = p;
            return;
        }
        while (r != NULL)
        {
            t = r;
            if (key < r->data)
            {
                r = r->LChild;
            }
            else if (key > r->data)
            {
                r = r->RChild;
            }
            else
            {
                return;
            }
        }
        p = new node(key);
        if (key < t->data)
        {
            t->LChild = p;
        }
        else
        {
            t->RChild = p;
        }
    }

    void InOrder(node *p)
    {
        if (p != NULL)
        {
            InOrder(p->LChild);
            cout << p->data << " ";
            InOrder(p->RChild);
        }
    }
};

int main()
{
    Tree t;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        t.insert(x);
    }
    t.InOrder(root);
    return 0;
}