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
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}

const int max_n = 3050;
ll val[max_n][max_n] = {0};
vector<vector<vector<ll>>> dp(max_n, vector<vector<ll>>(max_n, vector<ll>(4, 0)));

int main()
{
    int R, C, K;
    cin >> R >> C >> K;
    rep(i, K){
        ll r, c, v;
        cin >> r >> c >> v;
        val[r][c] = v;
    }
    rep1(i, R)rep1(j, C)rep(k, 4){

        chmax(dp[i][j][k], dp[i][j-1][k]);
        if (k!=0) chmax(dp[i][j][k], dp[i][j-1][k-1]+val[i][j]);
        chmax(dp[i][j][0], dp[i-1][j][k]);
        chmax(dp[i][j][1], dp[i-1][j][k]+val[i][j]);
    }

    ll ans = 0;
    rep(k, 4) chmax(ans, dp[R][C][k]);
    cout << ans << endl;
}

/*
dp[i][j][k] : i行j列に存在し、今までにk回拾った状態における価値の最大値

i, jにアイテムがないとき、
dp[i][j][k] = max(dp[i-1][j][3], dp[i][j-1][k], dp[i][j][min(k-1,0)]);
i, jにアイテムがあるとき、
dp[i][j][k] = max(dp[i-1][j][3], dp[i][j-1][k], dp[i][j][min(k-1,0)], dp[i][j-1][k-1]+v[i][j] (k!=0))

dp[0][j][k] = 0
dp[i][j][k] = 0

*/




