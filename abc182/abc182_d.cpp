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
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n){ cin >> a[i]; }

    vector<ll> maxlen(n);
    vector<ll> lastlen(n);

    ll maxtmp = -1e9;
    ll sum = 0;
    rep(i, n){
        sum += a[i];
        chmax(maxtmp, sum);
        maxlen[i] = maxtmp;
        lastlen[i] = sum; 
    }

    //show(maxlen);
    //show(lastlen);

    ll ans = 0;
    ll lsum = 0;
    rep(i, n){
        chmax(ans, lsum+maxlen[i]);
        lsum += lastlen[i];
    }
    cout << ans << endl;
}

