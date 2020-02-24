#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n;
    cin >> n;
    vector<P> info[n]; //info[i]: i人目の証言(i<=0 <= n-1)
    rep(i, n){
        int num; cin >> num;
        rep(j, num){
            int x, y;
            cin >> x >> y;
            info[i].emplace_back(--x, y);
        }
    }

    int ans = 0;
    rep(i, 1ll<<n){
        int cnt = 0;
        bool isok = true;
        rep(j, n){
            if(i>>j & 1){
                rep(k, info[j].size()){
                    if (info[j][k].second && !(i>>info[j][k].first & 1)){
                        isok = false; break;
                    } else if (!info[j][k].second && (i>>info[j][k].first & 1)){
                        isok = false; break;
                    }
                }
                cnt++;
            }
            if(!isok) break;
        }
        if(isok) ans = max(ans, cnt);
    }

    cout << ans << endl;
}

