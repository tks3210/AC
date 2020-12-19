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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, m){ cin >> a[i]; }

    sort(a.begin(), a.end());
    //show(a);
    int st = 1;
    vector<int> sp;

    
    rep(i, m){
        int tsp = a[i] - st;
        if (tsp != 0) sp.push_back(tsp);
        st = a[i]+1;
    }
    if (n+1-st != 0) sp.push_back(n+1-st);

    //show(sp);

    int minl = MOD;
    //not care
    if (sp.size() == 0) {cout << 0 << endl; return 0;}
    rep(i, sp.size()){
        chmin(minl, sp[i]);
    }

    int ans = 0;
    rep(i, sp.size()){
        ans += (sp[i] + minl - 1) / minl;
    }

    cout << ans << endl;
}

