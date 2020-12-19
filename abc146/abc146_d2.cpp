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


vector<vector<int>> tree;
struct line {
    int st, end;
    line(int st, int end): st(st), end(end){}
};

bool operator<(const line &a, const line&b){
    if (a.st == b.st){
        return a.end < b.end;
    } else {
        return a.st < b.st;
    }
}

map<line, int> lineinfo;

void dfs(int now, int par, int used){    
    int color = 0;
    for (auto next: tree[now]){
        if (next == par) continue;
        color++;
        if (color == used) color++;
        lineinfo[line{min(now, next), max(now, next)}] = color;
        dfs(next, now, color);
    }
}

int main()
{
    int n;
    cin >> n;
    tree.assign(n, vector<int>());

    vector<line> hen;
    rep(i, n-1){ 
        int a, b;
        cin >> a >> b; a--; b--; 
        tree[a].push_back(b);
        tree[b].push_back(a);
        hen.emplace_back(min(a,b), max(a,b));
    }

    dfs(0, -1, -1);
    int max_color = 0;
    rep(i, n-1) chmax(max_color, lineinfo[hen[i]]);
    cout << max_color << endl;
    rep(i, n-1) cout << lineinfo[hen[i]] << endl;

}