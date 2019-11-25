#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 10e13
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main()
{
    ll n;
    cin >> n;
    ll ans = INF;
    for (ll i = 1; i*i <= n; i++)
    {
        if (n % i == 0){
            ans = min(ans, i + (n/i) - 2);
        }
    }
    
    cout << ans << endl;

}

