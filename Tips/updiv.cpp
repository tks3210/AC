#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";} cout << endl;
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}
bool divfloor (ll x, ll y, ll& ans) {
    if(!y) return false;
    int mut = 1;
    if ((x < 0 && y >= 0) || (x >= 0 && y < 0)) mut = -1;
    ans = (abs(x)+abs(y)-1)/abs(y) * mut;
    return true;
}

int main(){
    int a, b;
    while(1){
        cin >> a >> b;
        ll ans;
        if(!divfloor(a, b, ans)) break;
        cout << ans;
    }

}