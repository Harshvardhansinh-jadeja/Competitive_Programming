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
    void levelOrder(node *p)
    {
        queue<node *> q;
        cout << p->data<<" ";
        q.push(p);
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            if (p->LChild)
            {
                cout << p->LChild->data<<" ";
                q.push(p->LChild);
            }
            if (p->RChild)
            {
                cout << p->RChild->data<<" ";
                q.push(p->RChild);
            }
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

    t.levelOrder(root);
    return 0;
}