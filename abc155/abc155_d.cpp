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

    ll l = MIN_AA;//OK
    ll r = MAX_AA;//NG
    while(abs(l - r) > 1){
        ll mid = (l + r) / 2;

        bool ok = [&]{
            ll tot = 0;
            rep(i, n){
                if (a[i] >= 0){
                    int l = -1, r = n;
                    while(abs(l-r) > 1){
                        int c = (l + r) / 2;
                        if (a[i]*a[c] < mid) l = c; else r = c;
                    }
                    tot += r;
                } else {
                    int l = -1, r = n;
                    while(abs(l-r) > 1){
                        int c = (l + r) / 2;
                        if (a[i]*a[c] < mid) r = c; else l = c; 
                    }
                    tot += n - r;
                }
                if (a[i] * a[i] < mid) tot--;
            }
            tot /= 2;
            return tot < k;
        }();
        if(ok) l = mid; else r = mid; 
    }

    cout << l << endl;
}

