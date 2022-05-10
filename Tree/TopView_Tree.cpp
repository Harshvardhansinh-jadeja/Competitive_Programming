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
    void Top(node* root, int dist, int level, map<int,pair<int,int>> &map)
    {
        if (root ==NULL)
        {
            return;
        }

        if (map.find(dist) == map.end() || level < map[dist].second)
        {
            map[dist] = {root->data, level};
        }
        Top(root->LChild, dist - 1, level + 1, map);
        Top(root->RChild, dist + 1, level + 1, map);
    }

    void Top(node *root)
    {
        map<int, pair<int, int>> map; //key : horizontal distance
                                      //Value first node value , second is Level
        Top(root, 0, 0, map);
        for (auto it : map)
        {
            cout << it.second.first << " ";
        }
    }

    void preOrder(node *p)
    {
        if (p)
        {
            cout << p->data << " ";
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
    t.Top(root);
    return 0;
}

