#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}
typedef tuple<int, int, int> P3;

int main()
{
    ll k, q;
    cin >> k >> q;
    vector<ll> d(k);
    rep(i, k) { ll tmp; cin >> tmp; d[i] = tmp;}
    rep(i, q){
        ll n, x, m;
        cin >>n>>x>>m;
        vector<ll> d_ = d;
        rep(j, k) d_[j] %= m;
        x %= m;

        vector<ll> mut(k, 0);
        rep(j, k) mut[j] = (n+(k-2)-j)/k;
        //show(mut);
        //show(d_);
        ll ans = n - 1;
        ll x_fin = x;
        rep(j, k) x_fin += mut[j] * d_[j];
        //cout << (x_fin/m) << " " << (x/m) << endl;
        ans -= (x_fin/m) - (x/m);
        rep(j, k) if(!d_[j]) {ans -= mut[j];}
 
        cout << ans << endl;
    }
}


