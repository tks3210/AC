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
    vector<vector<ll>> masu;


    int h, w, n, m;
    cin >> h >> w >> n >> m;
    masu.assign(h, vector<ll>(w, 0));

    vector<int> a(n);

    vector<vector<P>> Hstate(h);
    vector<vector<P>> Wstate(w);

    set<P> isblock;
    //lamp
    rep(i, n){ 
        P tmp;
        cin >> tmp.first >> tmp.second;
        tmp.first--; tmp.second--;
        Hstate[tmp.first].emplace_back(tmp.second, 1);
        Wstate[tmp.second].emplace_back(tmp.first, 1);
    }

    //block
    rep(i, m){
        P tmp;
        cin >> tmp.first >> tmp.second;
        tmp.first--; tmp.second--;
        Hstate[tmp.first].emplace_back(tmp.second, 0);
        Wstate[tmp.second].emplace_back(tmp.first, 0);
        isblock.insert(tmp);
    }

    rep(i, h) sort(Hstate[i].begin(), Hstate[i].end());
    rep(i, w) sort(Wstate[i].begin(), Wstate[i].end());

    ll ans = 0;
    rep(i, h)rep(j, w){
        P now = {i, j};
        // on block
        if (isblock.find(now) != isblock.end()) continue;

        //->
        auto xp = lower_bound(Hstate[i].begin(), Hstate[i].end(), P(j,0)) - Hstate[i].begin();
        if (xp < (int)Hstate[i].size()){
            if (Hstate[i][xp].second == 1){
                ans++;
                //cout << i+1 << j+1 << endl;
                continue;
            }
        }
        int xm = xp-1;
        if (xm >= 0){
            if (Hstate[i][xm].second == 1){
                ans++;
                //cout << i+1 << j+1 << endl;
                continue;
            }
        }

        int yp = lower_bound(Wstate[j].begin(), Wstate[j].end(), P(i,0)) - Wstate[j].begin();
        if (yp < Wstate[j].size()){
            if (Wstate[j][yp].second == 1){
                ans++;        
                //cout << i+1 << j+1 << endl;
                continue;
            }
        }
        int ym = yp-1;
        if (ym >= 0){
            if (Wstate[j][ym].second == 1){
                ans++;
                //cout << i+1 << j+1 << endl;
                continue;
            }
        }
    }
    cout << ans << endl;

}

