#include <bits/stdc++.h>
using namespace std;

class node
{
private:
    int data;
    node *Lchild;
    node *Rchild;

public:
    node(int d)
    {
        data = d;
        Lchild = NULL;
        Rchild = NULL;
    }
    friend class Tree;
};

node *root = NULL;
class Tree
{
public:
    void create()
    {
        node *p, *t;
        int x, y, z;
        queue<node *> q;

        cout << "Enter Value of Root node " << endl;
        cin >> x;
        root = new node(x);
        q.push(root);

        while (!q.empty())
        {
            p = q.front();
            q.pop();
            cout << "Enter Left child of " << p->data << endl;
            cin >> y;
            if (y != -1)
            {
                t = new node(y);

                p->Lchild = t;
                q.push(t);
            }
            cout << "Enter Right child of " << p->data << endl;
            cin >> z;
            if (z != -1)
            {
                t = new node(z);
                p->Rchild = t;

                q.push(t);
            }
        }
    }

    void PrintPreOrder(node *p, vector<int> &v)
    {
        if (p != NULL)
        {
            PrintPreOrder(p->Lchild, v);
            v.push_back(p->data);
            // cout << p->data << endl;
            PrintPreOrder(p->Rchild, v);
        }
    }
};

int main()
{
    vector<int> v;
    Tree t1;
    t1.create();
    t1.PrintPreOrder(root, v);

    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            cout << "No" << endl;
            break;
        }
        else
        {
            if (i == v.size() - 2)
            {
                cout << "Yes It's a Binary Tree" << endl;
            }
        }
    }

    return 0;
}