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
    ll a, v;
    cin >> a >> v;
    ll b, w;
    cin >> b >> w;
    ll t;
    cin >> t;

    ll diff = abs(a-b);
    ll vdiff = v-w;

    bool isok = false;
    if (vdiff > 0){
        if (vdiff * t >= diff){
            isok = true;
        }
    }
    if (isok) cout << "YES" << endl;
    else cout << "NO" << endl;
}


