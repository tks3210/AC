#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    ll a, b, c;
    cin >> a >> b >> c;
    bool ans = false;
    if (c-a-b <=0) {
        ans=false;
    } else {
        ll s = c-a-b;
        s = s*s;
        if (4*a*b<s){
            ans=true;
        } else {
            ans=false;
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

}

