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

    int Height(node *p)
    {
        if (p == NULL)
        {
            return 0;
        }
        else
        {

            int x, y;
            y = Height(p->RChild);
            x = Height(p->LChild);
            return (x > y ? x + 1 : y + 1);
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
    cout << t.Height(root) - 1 << endl;
    return 0;
}