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

/*
[tag]ダブリング

K回(>10^9)処理したあとの結果を求める系で使える。

A[i] = i状態の次の遷移とすると、
i状態の次の次の遷移は、B[i] = A[A[i]]で簡単に求められる。
同じように考えると、4つ先の遷移もB[B[i]]で簡単に求められる。

これを一般化すると
D[v][i] : iから2^v回遷移した状態を定義できる。


*/


int main()
{
    ll n, k;
    cin >> n >> k;
    const int depth = 62;
    vector<vector<int>> D(depth, vector<int>(n, 0));
    rep(i, n){ cin >> D[0][i]; D[0][i]--;}

    rep(d, depth-1){
        rep(i, n){
            D[d+1][i] = D[d][D[d][i]];
        }
    } 

    int st = 0;
    rep(d, depth-1){
        if (k & ((ll)1<<d)) st = D[d][st];
    }
    cout << st + 1 << endl;
}

