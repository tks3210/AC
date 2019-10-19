#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    vector<int> d;
    rep(i, n){ int tmp; cin >> tmp; d.push_back(tmp);}

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j =  i + 1; j < n; j++)
        {
            ans += d[i] * d[j];
        }
    }
    
    cout << ans << endl;

}

