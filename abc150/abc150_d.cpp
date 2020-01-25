#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

ll gcd(ll x, ll y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}

    int lcm_sum = a[0]/2;
    rep(i, n-1){
        lcm_sum = lcm(lcm_sum, a[i+1]/2);
    }
    int flag = 0;
    rep(i, n){
        if ((lcm_sum / (a[i]/2)) % 2 == 0) flag = 1;
    }
    if (flag){
        cout << "0" << endl;
    } else {
        int ans = 0;
        if (m >= lcm_sum){
            ans = 1 + (m - lcm_sum)/(lcm_sum*2);
        }
        cout << ans << endl;
    }
}

