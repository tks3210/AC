#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;

int mod;

int main()
{
    ll L, A, B;
    cin >> L >> A >> B;
    cin >> mod;

    ll ans = 0;
    //1~18桁の数字
    // a + xb
    ll ten = 1;
    for (int i = 1; i <= 18; i++)
    {
        ll l = ten, r = ten*10 - 1;
        if (A+B*(l  -1) < l) continue;
        if (A > r)
        ll na = 0; //初項
        ll nl = 0; //長さ
        {
            ll x = (l-a) / b;
        }
        ten *= 10;
    }
    


}

