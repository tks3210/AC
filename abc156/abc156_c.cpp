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


int main()
{
    int n;
    cin >> n;
    vector<int> x;
    rep(i, n){ int tmp; cin >> tmp; x.push_back(tmp);}

    ll sum_x = 0;
    ll sum_xx = 0;
    rep(i, n){
        sum_x += x[i];
        sum_xx += x[i] * x[i];
    }

    ll ans = MOD;
    
    rep(p, 100){
        ll cal = sum_xx + (p+1)*(p+1)*n -2*(p+1)*sum_x;  
        ans = min(ans, cal);
    }

    cout << ans << endl;
}

