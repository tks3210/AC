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
    int n;
    cin >> n;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}
    vector<ll> sum(n+1);
    sum[0] = 0;
    rep(i, n) { sum[i+1] += sum[i] + a[i];}

    ll ans = 0;
    
    // multiset<ll> sp;
    // rep(i, n+1){
    //     ans += sp.count(sum[i]);
    //     sp.insert(sum[i]);
    // }
    map<ll, int> mp;
    rep(i, n+1){
        if (mp.find(sum[i]) != mp.end()){
            ans += mp[sum[i]];
            mp[sum[i]]++;
        } else {
            mp.insert({sum[i], 1});
        }
    }
    cout << ans << endl;
}

