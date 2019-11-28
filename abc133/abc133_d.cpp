#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);        
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int hugo = (i%2 == 0) ? 1: -1;
        ans += hugo * a[i];
    }
    cout << ans;
    for (int i = 1; i < n; i++)
    {
        ans = (2 * a[i - 1]) - ans;
        cout << " " <<ans;
    }
    cout << endl;
}

