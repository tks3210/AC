#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;


int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    ll div10 = 10;
    if (n%2 != 1){
        while(n/div10 > 0){
            ans += n/div10;
            div10 *= 5;
        }
    }

    cout << ans << endl; 
}

