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
    int n; string s;
    cin >> n;
    cin >> s;

    vector<int> w_froml;
    vector<int> r_fromr;
    rep(i, n){
        if (s[i] == 'W') w_froml.push_back(i);
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (s[i] == 'R') r_fromr.push_back(i);
    }
    
    int ans = 0;
    for (int i = 0; i < min(w_froml.size(), r_fromr.size()); i++)
    {
        if (w_froml[i] > r_fromr[i]) break;
        ans++;
    }
    

    cout << ans << endl;

}

