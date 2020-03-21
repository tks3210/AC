#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

int dp[110][10010] = {0};
int main()
{
    int n;
    cin >> n;
    vector<int> p;
    rep(i, n){ int tmp; cin >> tmp; p.push_back(tmp);}

    dp[0][0] = 1;
    rep(i, n+1){
        rep(j, n*100+1){
            if (j < p[i]) dp[i+1][j]=dp[i][j];
            else dp[i+1][j]=((dp[i][j-p[i]]==1)||(dp[i][j]));
        }
    }

    // rep(i, n+1){
    //     rep(j, n*10){
    //         cout << dp[i][j] << ":";
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    rep(i, n*100+1){
        if(dp[n][i]) ans++;
    }
    cout << ans << endl;
}


