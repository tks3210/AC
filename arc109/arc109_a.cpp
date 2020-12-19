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

int dp[2][101] = {0};
int x, y;

void dfs(int bill, int floar){
    if (bill == 0){
        if (floar > 0){
            if(chmin(dp[1][floar-1],dp[bill][floar] + x)) dfs(1,floar-1);
        }
    } else {
        if (floar < 100){
            if (chmin(dp[0][floar+1],dp[bill][floar] + x)) dfs(0, floar+1);
        }
    }
    //同じフロア間の移動
    if (chmin(dp[1-bill][floar],dp[bill][floar] + x)) dfs(1-bill,floar);   

    //同じビル間の移動
    if (floar < 100){
        if (chmin(dp[bill][floar+1],dp[bill][floar] + y)) dfs(bill,floar+1);
    }
    if (floar > 0){
        if (chmin(dp[bill][floar-1],dp[bill][floar] + y)) dfs(bill,floar-1);
    }

}



int main()
{
    int a, b;
    cin >> a  >> b >> x >> y;

    rep(i, 2){
        rep(j, 101){
            dp[i][j] = 1e9;
        }
    }
    dp[0][a] = 0;
    dfs(0, a);

    cout << dp[1][b] << endl;


    // rep1(i, 100){
    //     cout << dp[0][i] << ":"<<dp[1][i] << endl;

    // }
}

