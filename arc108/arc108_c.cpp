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

vector<set<int>> tree;
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
int n;
vector<int> ans;
void dfs(int now, int val, bool sel){
    if(sel) ans[now] = val;
    else ans[now] = (val+1)%n; 

    for (auto next: tree[now]){
        if (ans[next] != -1) continue;
        int c = lineinfo[line{min(now,next), max(now,next)}];
        if (c == ans[now]){
            dfs(next, c, false);
        } else {
            dfs(next, c, true);
        }
    }
}

int main()
{
    int m;
    cin >> n >> m;
    tree.assign(n, set<int>());
    ans.assign(n, -1);
    rep(i, m){
        int u, v, c;
        cin >> u >> v >> c; u--; v--; c--; 
        tree[u].insert(v);
        tree[v].insert(u);

        lineinfo[line{min(u,v), max(u,v)}] = c;//多重辺は無視
    }

    dfs(0, 0, true);

    rep(i, n){
        cout << ans[i]+1 << endl;
    }

}

