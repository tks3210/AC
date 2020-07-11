#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef unsigned long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

#define THREAD (ll)1000'000'000'000'000'000

int main()
{
    int n;
    cin >> n;
    vector<ll> a;
    rep(i, n){ ll tmp; cin >> tmp; a.push_back(tmp);}
    rep(i, n){
        if (a[i] == 0){
            cout << "0" << endl; return 0;
        }
    }
    ll sum = 1;
    rep(i, n){
        ll div = THREAD/sum;
        if (div < a[i]){
            cout << "-1" << endl;
            return 0;
        }
        sum *= a[i];
    }
    cout << sum << endl;
}

