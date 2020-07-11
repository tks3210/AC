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
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a);
    vector<ll> t(b);
    vector<ll> x(q);
    rep(i, a) cin >> s[i];
    rep(i, b) cin >> t[i];
    rep(i, q) cin >> x[i];
    
    rep(i, q){
        int sitr = lower_bound(s.begin(), s.end(), x[i]) - s.begin();
        int titr = lower_bound(t.begin(), t.end(), x[i]) - t.begin();

        ll len = (ll)1e12;
        // =>=>
        if (sitr != a && titr != b) len = min(len, max(abs(x[i]-s[sitr]), abs(x[i]-t[titr])));
        // <=<= 
        if (sitr != 0 && titr != 0) len = min(len, max(abs(x[i]-s[sitr-1]), abs(x[i]-t[titr-1]))); 
        // 
        if (sitr != 0 && titr != b) {
            ll tlen = min(abs(x[i]-s[sitr-1]), abs(x[i]-t[titr]));
            len = min(len, tlen + abs(s[sitr-1] -  t[titr]));
        }
        if (sitr != a && titr != 0) {
            ll tlen = min(abs(x[i]-s[sitr]), abs(x[i]-t[titr-1]));
            len = min(len, tlen + abs(s[sitr] -  t[titr-1]));
        }
        cout << len << endl;
    }

}

