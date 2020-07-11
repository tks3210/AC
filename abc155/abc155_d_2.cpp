#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";} cout << endl;
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


#define MAX_AA  (ll)1e18;
#define MIN_AA  (ll)-1e18;


int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a;
    rep(i, n){ ll tmp; cin >> tmp; a.push_back(tmp);}
    sort(a.begin(), a.end());
    //
    ll l = -1e18-1;
    ll r = 1e18+1;
    while(abs(r-l) > 1){
        //二分探索によりxより小さいものがk個以上ある最大のxを求める。
        ll sum = 0;
        ll mid = (l+r)/2;
        for (int i = 0; i < n; i++)
        {
            int tl = -1;
            int tr = n;
            if (a[i] >= 0){
                while(abs(tl-tr) > 1){
                    //tmid が正の時 T 側
                    int tmid = (tl + tr)/2;
                    if (a[i]*a[tmid] <= mid) tl = tmid;
                    else tr = tmid;
                }
                sum += tl+1;
                if (i<=tl) sum--;
            } else {
                while(abs(tl-tr) > 1){
                    int tmid = (tl + tr)/2;
                    if (a[i]*a[tmid] <= mid) tr = tmid;
                    else tl = tmid;
                }
                sum += n-tr;
                if (tr<=i) sum--;
            }
        }
        sum /= 2;
        //cout << sum << endl;
        if (sum >= k){
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}

