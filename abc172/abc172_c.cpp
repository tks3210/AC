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


int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}
    vector<ll> b;
    rep(i, m){ int tmp; cin >> tmp; b.push_back(tmp);}

    vector<ll> asum(n+1, 0);
    vector<ll> bsum(m+1, 0);

    rep(i, n) asum[i+1] = asum[i] + a[i];
    rep(i, m) bsum[i+1] = bsum[i] + b[i];

    ll ans = 0;
    rep(i, n+1){
        ll t = asum[i];
        ll remain = k-t;
        if (remain < 0) continue;
        auto itr = upper_bound(bsum.begin(), bsum.end(), remain) - bsum.begin();
        ll tans = i + itr - 1;
        ans = max(tans, ans);
    }

    cout << ans << endl;
}

