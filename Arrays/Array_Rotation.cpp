//Only test case 8 is failing bcz of TLE
#include <bits/stdc++.h>
using namespace std;

 int  main()
{
    vector<long long int > v;
    long long int  n,rotation;
    cin >> n;
    cin >> rotation;
    for (long long int  i = 0; i < n; i++)
    {
        long long int  x;
        cin >> x;
        v.push_back(x);
    }

    for (long long int  j = 0; j < rotation; j++)
    {
        long long int  saved = v[0];
        for (long long int  i = 0; i < v.size(); i++)
        {
            if (i == v.size() - 1)
            {
                v[i + 1] = saved;
            }
            v[i] = v[i + 1];
        }
    }

    for (long long int  i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
