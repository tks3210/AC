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
    vector<vector<int>> masu;
    int h, w, n, m;
    cin >> h >> w >> n >> m;
    masu.assign(h, vector<int>(w, 0));

    //lamp:2, on:1, off:0, block:-1 
    //lamp
    rep(i, n){ 
        P tmp;
        cin >> tmp.first >> tmp.second;
        tmp.first--; tmp.second--;
        masu[tmp.first][tmp.second] = 2;
    }
    //block
    rep(i, m){
        P tmp;
        cin >> tmp.first >> tmp.second;
        tmp.first--; tmp.second--;
        masu[tmp.first][tmp.second] = -1;
    }

    rep(i, h){
        bool on = false;
        for (int j = 0; j < w; j++)
        {
            if (masu[i][j] == -1){ on = false; continue;}
            if (masu[i][j] == 2) on=true;
            else if (on) masu[i][j] = 1;
        }
        on = false;
        for (int j = w-1; j >= 0; j--)
        {
            if (masu[i][j] == -1){ on = false; continue;}
            if (masu[i][j] == 2) on=true;
            else if (on) masu[i][j] = 1;
        }
    }
    rep(j, w){
        bool on = false;
        for (int i = 0; i < h; i++)
        {
            if (masu[i][j] == -1){ on = false; continue;}
            if (masu[i][j] == 2) on = true;
            else if (on) masu[i][j] = 1;
        }
        on = false;
        for (int i = h-1; i >= 0; i--)
        {
            if (masu[i][j] == -1){ on = false; continue;}
            if (masu[i][j] == 2) on=true;
            else if (on) masu[i][j] = 1;
        }
    }

    int ans = 0;
    rep(i, h)rep(j, w){
        if (masu[i][j] > 0) ans++;
    }
    cout << ans << endl;
}

