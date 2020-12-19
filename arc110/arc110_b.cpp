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
    int n;
    string s;
    cin >> n;
    cin >> s;

    vector<bool> hant(3, false);
    //pat 110;
    bool tmp = true;
    rep(i, n){
        if (i%3 == 0 && s[i] != '1') tmp = false;
        if (i%3 == 1 && s[i] != '1') tmp = false;
        if (i%3 == 2 && s[i] != '0') tmp = false;
    }
    if (tmp) hant[0] = true;

    //pat 10110...
    tmp = true;
    rep(i, n){
        if (i%3 == 0 && s[i] != '1') tmp = false;
        if (i%3 == 1 && s[i] != '0') tmp = false;
        if (i%3 == 2 && s[i] != '1') tmp = false;
    }
    if (tmp) hant[1] = true;

    //pat 0110...
    tmp = true;
    rep(i, n){
        if (i%3 == 0 && s[i] != '0') tmp = false;
        if (i%3 == 1 && s[i] != '1') tmp = false;
        if (i%3 == 2 && s[i] != '1') tmp = false;
    }
    if (tmp) hant[2] = true;

    if (!hant[0] && !hant[1] && !hant[2]) {cout << 0 << endl; return 0;}
    if (n <= 2){
        if (s == "11" || s == "10" || s == "0") {cout << (ll)1e10 << endl; return 0;}
        if (s == "1") {cout << (ll)1e10*2 << endl; return 0;}
        if (s == "01") {cout << (ll)1e10-1 << endl; return 0;}
    }
    ll ans = 0;
    ll rem = 0;
    if (hant[0]){
        rem = (ll)1e10*3 - n;
    } else if (hant[1]){
        rem = (ll)1e10*3 - n - 1; 
    } else if (hant[2]){
        rem = (ll)1e10*3 - n - 2;
    }
    ans = 1 + rem/3;

    cout << ans << endl;

}

