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
    int a, b;
    cin >> a >> b;

    int ans = b * 10;

    bool ansb = false;
    rep(i, 10){
        int res = ans + i;
        if (res*2/25 == a){
            ansb = true;
            ans = res;
            break;
        }
    }

    if(ansb) cout << ans << endl;
    else cout << "-1" << endl;
}

