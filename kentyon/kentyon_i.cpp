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


int dp[55][10050][55]={0};

int main()
{
    int w, n, k;
    cin >> w >> n >> k;
    vector<P> a(n+1);

    rep(i, n){ cin >> a[i].first >> a[i].second;}

    //dp[i][j][k] : j番目までのソフト幅にi番目までのスクショをはる時の価値最大
    //dp[i][j] = max(dp[i-1][j-a[i]]+b[i], dp[i-1][j])
    //dp[0][j] = 0;
    //dp[i][0] = 0;

    rep(i,n){
        rep(j,w+1){
            rep(r, k){
                if (j < a[i].first){
                    dp[i+1][j][r] = dp[i][j][r];
                } else {
                    dp[i+1][j][r+1] = max(dp[i][j-a[i].first][r]+a[i].second, dp[i][j][r+1]);
                }
            }
        }
    }

    // rep(i,n+1){
    //     rep(j,w+1){
    //         cout << dp[i][j][k] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = 0;
    rep1(r, k) ans = max(ans, dp[n][w][r]);

    cout << ans << endl;
}

