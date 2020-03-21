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
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}

    int r = 0;
    ll sum = 0;
    ll ans_ = 0;
    rep(l, n){
        while(a[r] + sum < k){
            if (r == n) break; 
            sum += a[r];
            r++;
        }
        //cout << l << ":" << r << ":" << sum << endl;
        ans_ += r - l;
        sum -= a[l];
    }

    cout << (ll)(n * (n + 1) / 2) - ans_ << endl;
}

