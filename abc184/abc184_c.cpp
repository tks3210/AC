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

/*



*/

int main()
{
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    ll rc1p = r1+c1;
    ll rc1m = r1-c1;
    ll rc2p = r2+c2;
    ll rc2m = r2-c2;
    ll kyori = abs(r1-r2)+abs(c1-c2);

    int ans = 3;
    if (r1==r2 && c1==c2){
        ans = 0;
    } else if (rc1p == rc2p || rc1m == rc2m){
        ans = 1;
    } else if (kyori <= 3){
        ans = 1;
    } else if ((rc1p%2) == (rc2p)%2){
        ans = 2;
    } else if (abs(rc1p-rc2p)<=3 || abs(rc1m-rc2m)<=3){
        ans = 2;
    } else if (kyori <= 6){
        ans = 2;
    }
    cout << ans << endl;

}

