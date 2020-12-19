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
const long long INF = 1LL<<60;

const int n_max = 5050;

vector<ll> p(n_max, 0);
vector<ll> c(n_max, 0);


int main()
{
    int N, K;
    cin >> N >> K;
    rep(i, N) cin >> p[i], --p[i];
    rep(i, N) cin >> c[i];

    //2^32
    const int dep = 32;
    vector<vector<int>> next(dep, vector<int>(N));
    vector<vector<ll>> val(dep, vector<ll>(N)), all(dep, vector<ll>(N));
    /*
    next[d][v] := 頂点vから2^dだけ進んだ頂点
    val[d][v] := 頂点vから2^dだけ進んだ中での総和
    all[d][v] := 頂点vから出発して2^d以下の距離進んだ中での総和の最大値

    => 求めたいのはK以下の距離進んだ中での総和の最大値
    */
    rep(v, N){
        next[0][v] = p[v];
        val[0][v] = all[0][v] = c[v];
    }
    rep(d, dep-1)rep(v, N){
        next[d+1][v] = next[d][next[d][v]];
        val[d+1][v] = val[d][v] + val[d][next[d][v]];
        all[d+1][v] = max(all[d][v], val[d][v] + all[d][next[d][v]]);
    }
    ll ans = -INF;
    rep(v, N){
        //vからstartしてK以下の距離進んだ中での総和の最大値を求める。
        ll sum = 0;
        chmax(ans,all[0][v]);
        int st = v;
        for (int d = 0; d < dep-1; d++)
        {
            if (K&(1LL<<d)){
                chmax(ans, sum + all[d][st]);//vからstartしてKの下位d+1[bit]分進んだ場合の最大値で緩和する。
                sum += val[d][st];//vからstartしてKの下位d+1[bit]分進んだ場合の総和
                st = next[d][st];//vからstartしてKの下位d+1[bit]分進んだ場合の位置
            }
        }
    }
    cout << ans << endl;
}
