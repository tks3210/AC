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

ll big = 1e16;

bool isbig(ll k, ll d){
    if (big/k < d){
        return true;
    } else {
        return false;
    }

}

int main()
{
    ll x, k, d;
    cin >> x >> k >> d;

    ll ans = 0;
    if (isbig(k,d) || abs(x) <= k*d) {
        if ((abs(x)/d - k)%2 == 0){
            //近づく
            ans = abs(x)%d;
        } else {
            //追い越す
            ans = abs((abs(x)%d)-d);
        }
    } else {
        ans = abs(x) - k*d;
    }

    cout << ans << endl;


}

