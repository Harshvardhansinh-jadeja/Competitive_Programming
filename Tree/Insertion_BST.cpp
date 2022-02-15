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
    friend class BST;
};

node *root = NULL;
class BST
{
public:
    node *RInsert(node *p, int key)
    {
        node *t;
        if (p == NULL)
        {
            t = new node(key);
            return t;
        }
        if (key < p->data)
        {
            p->LChild = RInsert(p->LChild, key);
        }
        else if (key > p->data)
        {
            p->RChild = RInsert(p->RChild, key);
        }
        return p;
    }
    void preOrder(node *p){
        if(p){
        cout<<p->data<<" ";
        preOrder(p->LChild);
        preOrder(p->RChild);
        }
    }
};

int main()
{
    BST t;
    int n;
    cin >> n;
    int y;
    cin >> y;
    root = t.RInsert(root, y);
    for (int i = 1; i < n; i++)
    {
        int x;
        cin >> x;
        t.RInsert(root, x);
    }
    t.preOrder(root);
    return 0;
}