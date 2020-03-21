#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

const int node_num = 105;
vector<int> graph[node_num];
int visited[node_num];

bool fds(int v, int p){
    if (visited[v] == 1) return false;
    visited[v] = 1;
    for(auto next: graph[v]){
        if (next == p) continue;
        if (!fds(next, v)) return false;
    }
    //cout << v << p << endl;
    return true;
}


int main()
{
    int n, m;
    cin >> n >> m;
    rep(i, m){ 
        int u,v; cin >> u >> v; 
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans = 0;
    rep(i, n){
        if (visited[i] != 0) continue;
        if (fds(i, -1)) ans++;
    }
    cout << ans << endl;    
}

