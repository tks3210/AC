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


int main()
{
    ll n, x, m;
    cin >> n >> x >> m;
    
    const int depth = 40;

    //next[d][v]: a_iがvの時のa_(i+2^v)の値
    vector<vector<ll>> next(depth, vector<ll>(m));
    //val[d][v]: a_iがvの時の[a_i a_(i+2^v) )の総和
    vector<vector<ll>> val(depth, vector<ll>(m));

    rep(v, m) next[0][v] = ((ll)v*(ll)v)%m;
    rep(v, m) val[0][v] = v;

    rep(d, depth-1)rep(v, m){
        next[d+1][v] = next[d][next[d][v]];
        val[d+1][v] = val[d][v] + val[d][next[d][v]];
    }

    ll ans = 0;
    int st = x;
    rep(d, depth-1){
        if(n&(1LL<<d)){
            ans += val[d][st];
            st = next[d][st];
        }
    }

    cout << ans << endl;
}

