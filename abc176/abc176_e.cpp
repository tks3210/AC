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
    int h, w, m;
    cin >> h >> w >> m;

    set<P> targ;
    vector<int> H(h), W(w);
    rep(i, m){
        P tmp;
        cin >> tmp.first >> tmp.second;
        tmp.first--;
        tmp.second--;
        targ.insert(tmp);
        H[tmp.first]++;
        W[tmp.second]++;
    }

    int hmax = 0;
    int wmax = 0;
    rep(i, h) chmax(hmax, H[i]);
    rep(i, w) chmax(wmax, W[i]);
    vector<int> Hmax, Wmax;
    rep(i, h) if (H[i] == hmax) Hmax.push_back(i);
    rep(i, w) if (W[i] == wmax) Wmax.push_back(i);

//    show(Hmax);
//    show(Wmax);
    
    rep(i, Hmax.size())rep(j, Wmax.size()){
        if (targ.find(make_pair(Hmax[i], Wmax[j])) == targ.end()){
            cout << hmax+wmax << endl;
            return 0;
        }
    }
    cout << hmax+wmax -1 << endl;

}

