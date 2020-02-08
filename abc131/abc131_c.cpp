#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(ll x, ll y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

int main()
{
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    ll ans = B-A+1;
    ll cdiv = B/C - (A-1)/C;
    ll ddiv = B/D - (A-1)/D;
    ll cddiv = B/lcm(C, D) - (A-1)/lcm(C, D);
    ans -= cdiv + ddiv - cddiv; 

    cout << ans << endl;
}

