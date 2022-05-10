#include <bits/stdc++.h>
using namespace std;

int main()
{
    float n;
    cin >> n;
    vector<float> v;

    for (int i = 0; i < n; i++)
    {
        float x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < n; i++)
    {

        if (v[i] >= 38)
        {
            if ((ceil(v[i]/5)*5) - v[i] < 3)
            {
                cout << (ceil(v[i]/ 5)*5) << endl;
            }
            else
            {
                cout << v[i] << endl;
            }
        }
        else
            {
                cout << v[i] << endl;
            }
    }

    return 0;
}