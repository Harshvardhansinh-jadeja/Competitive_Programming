#include <bits/stdc++.h>
using namespace std;

class node
{
public:
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

    node *LCA(node *p, int n1, int n2)
    {
        if (p == NULL)
        {
            return NULL;
        }
        if (p->data > n1 && p->data > n2)
        {
            return LCA(p->LChild, n1, n2);
        }
        if (p->data < n1 && p->data < n2)
        {
            return LCA(p->RChild, n1, n2);
        }
        return p;
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
    int n1, n2;
    cin >> n1 >> n2;
    cout << t.LCA(root, n1, n2)->data << endl;

    return 0;
}