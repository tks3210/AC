#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> a;
    rep(i, n){ ll tmp; cin >> tmp; sum += tmp; a.push_back(sum);}

    ll mindif = 1e10;
    rep(i, n){ mindif = min(mindif, abs(a[i]*2 - sum));}

    printf("%lld\n", mindif);
}

