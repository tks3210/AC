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

    int keta = 10;
    rep(i, 10){
        ll tmp = 1;
        rep(j, i){
            tmp *= 10;
        }

        ll nedan = tmp * a + ((ll)(i + 1)) * b;

        if (nedan > x){
            keta = i;
            break;
        }
    }
    ll ans = 0;
    if (keta == 10){
        ans = 1e9;
    } else if(keta == 0){
        ans = 0;
    } else {
        ll tmp = 1;
        rep(i, keta){
            tmp *= 10;
        }
        ans = min(tmp - 1,(x - (b * (ll)keta)) / a);
    }
    
    cout << ans << endl;

}

