#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1ll < 60;
int main()
{
    ll n, x, d;
    cin >> n >> x >> d;

    if (d == 0){
        if (x == 0){
            cout << 1 << endl;
        } else {
            cout << n + 1 << endl;
        }
        return 0;
    }

    map<ll, vector<P>> mp;
    // iX + jD
    rep(i, n + 1){
        ll start = i*x;
        ll left = (ll)i*(i-1)/2;
        ll len = (ll)i*(n-i) + 1;
        start += left*d;     // iX + jD(j:min)
        mp[(start%d + d)%d].emplace_back(start, len);      //map
        //printf("%d %lld %lld %lld\n", i,(start%d + d)%d, start, len); 
    }

    ll ans = 0;
    for (auto p: mp){
        
        auto stra = p.second;
        for (auto& i : stra){
            i.first = (i.first - p.first) / d;
        }
        // int m = stra.size();
        // rep(i,m) stra[i].first = (stra[i].first-p.first)/d;

        vector<P> range;
        for (auto i : stra){
            range.emplace_back(i.first, 1);
            range.emplace_back(i.first + i.second, -1);
        }

        sort(range.begin(), range.end());
        ll cnt = 0; 
        ll bef = -INF;
        for (auto i : range){
            //printf("%lld, %lld\n",i.first, i.second);
            if (cnt) ans += i.first - bef;
            bef = i.first;
            cnt += i.second;

        }
    }
    cout << ans << endl;
    return 0;
}