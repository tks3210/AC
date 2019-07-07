#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1000000007;
int main()
{
    int n, k;
    vector<pair<int, int>> a;

    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        if (tmp1 > tmp2){ 
            a.push_back(make_pair(tmp2, tmp1));
        } else {
            a.push_back(make_pair(tmp1, tmp2));
        }
    }
    
    sort(a.begin(), a.end());

    for (auto i: a)
    {
        cout << i.first << " " << i.second << endl;
    }
    
    ll ans;
    for (int i = 2; i <= k; i++)
    {
        ans = ans * i % mod;
    }
    cout << ans;


}

