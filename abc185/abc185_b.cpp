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
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<P> ab(m);
    rep(i, m){ cin >> ab[i].first >> ab[i].second; }


    int time = 0;
    int bat = n;
    bool ans = true;
    rep(i, m){
        //touchaku
        bat -= ab[i].first - time;
        if (bat <= 0) {ans = false; break;}
        //charge
        bat += ab[i].second - ab[i].first;
        time = ab[i].second;
        chmin(bat, n);
        //cout << bat << endl;
    }
    bat -= t - time;
    //cout << bat << endl;
    if (bat <= 0) {ans = false;}

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

}

