#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    vector<int> d;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        d.push_back(tmp);
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if ((d[i] > d[i - 1] && d[i] < d[i + 1]) ||
        (d[i] < d[i - 1] && d[i] > d[i + 1]))
        {
            ans++;
        }
    }
    cout << ans;    
}

