#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> h;
    rep(i, n){ ll tmp; cin >> tmp; h.push_back(tmp);}

    sort(h.begin(), h.end());

    ll ans = 0;
    if (n <= k){
        ans = 0;
    } else {
        rep(i, n-k){
            ans += h[i];
        }
    }
    cout << ans << endl;
}

