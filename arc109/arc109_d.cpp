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
    cin >> n;

    vector<pair<P, int>> ku(n);
    rep(i, n){ 
        P p[3];
        cin >> p[0].first >> p[0].second >> p[1].first >> p[1].second >> p[2].first >> p[2].second; 

        int x = p[0].first; chmax(x, p[1].first); chmax(x, p[2].first);
        int y = p[0].second; chmax(y, p[1].second); chmax(y, p[2].second);

        int dx = 3*x - (p[0].first + p[1].first + p[2].first);
        int dy = 3*y - (p[0].second + p[1].second + p[2].second);
        int sisei = 0;
        if (dx==2 && dy==2) sisei = 0;
        else if (dx==2 && dy==1) sisei = 1;
        else if (dx==1 && dy==1) sisei = 2;
        else if (dx==1 && dy==2) sisei = 3;
        else sisei = -1;
        ku[i] = {{x,y}, sisei};
    }

    rep(i, n){
        cout << ku[i].first.first << "," << ku[i].first.second << "::" << ku[i].second<< endl;
    }
}

