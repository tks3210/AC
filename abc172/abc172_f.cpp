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
    vector<ll> a;
    rep(i, n){ ll tmp; cin >> tmp; a.push_back(tmp);}

    ll sumbit = 0;
    for (int i = n-1; i >= 2; i--)
    {
        sumbit ^= a[i];
    }
    cout << sumbit << endl;

    ll ans = -1;
    for (ll i = 0; i*i < a[0]; i++)
    {
        ll sumbit2 = (a[0]-i)^(a[1]+i);
        if (sumbit == sumbit2){
            ans = i;
            break;
        }
    }
    
    cout << ans << endl;

}

