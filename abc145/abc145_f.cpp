#include <bits/stdc++.h>
using namespace std;
#define MOD (ll)1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;

#define N_MAX 305
vector<vector<ll>> dp(N_MAX, vector<ll>(N_MAX, MOD*(ll)N_MAX));
int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> h;
    h.push_back(0);
    rep(i, n){ int tmp; cin >> tmp; h.push_back(tmp);}

    // dp[x][y]: x は右端、yはサイズ
    rep(i,n) dp[i][0] = 0;
    // 推移条件の例外となるため最初はh[i]を与える
    rep(i,n+1) dp[i][1] = h[i];
    
    for (int x = 1; x <= n; x++)
    {
        for (int y = 2; y <= n; y++)
        {   
            for (int i = y-1; i <= x-1; i++)
            {
                dp[x][y] = min(dp[x][y], dp[i][y-1]+max((ll)0, h[x]-h[i]));
            }            
        }
    }

    ll ans = MOD*N_MAX;
    for (int x = 1; x <= n; x++)
    {
        if (x < n-k) continue;
        ans = min(ans, dp[x][n-k]);
    }
    
    cout << ans << endl;
}

