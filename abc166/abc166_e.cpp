#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n;
    cin >> n;
    vector<int> a;


    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}

    map<int, int> mp;

    rep(i, n){
        if (mp.find(a[i]-i) == mp.end()){
            mp.insert({a[i]-i, 1});
        } else {
            mp[a[i]-i]++;
        }
    }

    ll ans = 0;
    rep(i, n){
        mp[a[i]-i]--;

        int key = -a[i]-i;
        ans += mp[key];
    }
    cout << ans << endl;
}

