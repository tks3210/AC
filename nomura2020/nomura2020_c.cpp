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
    vector<int> a(n+1);
    rep(i, n+1){ cin >> a[i]; }
    vector<int> a_rev;
    a_rev = a;
    reverse(a_rev.begin(), a_rev.end());

    vector<ll> a_limit(n+1, 0);

    a_limit[n] = a[n];
    for (int i = n-1; i >= 0; i--)
    {
        a_limit[i] = a_limit[i+1] + a[i];
    }
    //show(a_limit);
    ll node = 1;
    ll ans = 0;
    rep(i, n+1){
        chmin(node, a_limit[i]); //限界値で丸める
        ans += node;
        node -= a[i];// 葉っぱを引く
        if (node < 0) {
            cout << -1 << endl;
            return 0;
        }
        node *= 2;//　二分木化する
    }
    cout << ans << endl;
}

