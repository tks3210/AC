#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;


int main()
{
    ll a, b, x;
    cin >> a >> b >> x;

    ll l = 0;
    ll r = 1e9+1;

    while(r-l > 1){
        ll m = (l+r)/2;
        ll sum = m*a;
        int keta=0;
        int tm = m;
        while(tm!=0) {tm/=10; keta++;}
        sum += keta*b;
        //cout << sum << endl;
        if (sum > x){
            r = m;
        } else {
            l = m;
        }
    }

    cout << l << endl;

}

