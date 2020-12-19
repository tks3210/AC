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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n){ cin >> a[i]; }

    ll l = 0;
    ll r = 1000000000;
    while(abs(r-l) > 1){
        ll mid = (l+r)/2;
        ll tcut = 0;
        rep(i, n){
            tcut += ((a[i] + mid -1) /mid) -1;           
        }
        if (tcut > k){
            //over
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << r << endl;

}

