#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    string s;
    cin >> s;

    vector<int> dp(2019,0);

    ll ans = 0;
    rep(i, s.size()){
        vector<int> tdp(2019,0);
        int c = s[i] - '0';

        for (int j = 0; j < 2019; j++)
        {
            //if (dp[j] == 0) continue;
            int new_key = j*10+c;
            new_key %= 2019;
            tdp[new_key] = dp[j];
        }
        tdp[c]++;        

        dp = tdp;
        ans += dp[0];
        // for(auto itr = dp.begin(); itr != dp.end(); ++itr){
        //     cout << itr->first << ":" << itr->second << endl;
        // }
        // cout << endl;
    }

    cout << ans << endl;

}

