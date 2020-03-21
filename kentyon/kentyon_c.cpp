#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    string s;
    cin >> s;
    int n = s.size();
    ll ans = 0;
    rep(i, 1<<(n-1)){
        vector<ll> tans;
        ll tsum = 0;
        rep(j, n-1){
            ll num = s[j]-'0';
            tsum += num;
            if ((i>>j)&1){
                //cout << tsum << endl;
                tans.push_back(tsum);
                tsum = 0;
            }
            tsum*=10;
        }
        tans.push_back(tsum+(s[n-1]-'0'));
        rep(j, tans.size()){
            ans += tans[j];
        }
    }

    cout << ans << endl;
}

