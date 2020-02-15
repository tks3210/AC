#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;

const int INF = 1001001001;

#define MAX_N 2510
vector<int> to[MAX_N];
vector<int> rto[MAX_N];
bool reachableFrom1[MAX_N];
bool reachableToN[MAX_N];
bool ok[MAX_N];
int d[MAX_N];

void dfs(int v){
    if (reachableFrom1[v]) return;
    reachableFrom1[v] = true;
    for (int u: to[v]){
        dfs(u);
    }
}

void rdfs(int v){
    if (reachableToN[v]) return;
    reachableToN[v] = true;
    for (int u: rto[v]){
        rdfs(u);
    }
}


int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    //tuple
    vector<tuple<int, int, int>> edges;
    rep(i, m){ 
        int tmpa, tmpb, tmpc;
        cin >> tmpa >> tmpb >> tmpc;
        tmpa--;
        tmpb--;
        tmpc -= p; tmpc = -tmpc;
        edges.emplace_back(tmpa, tmpb, tmpc);
        to[tmpa].push_back(tmpb);
        rto[tmpb].push_back(tmpa);
    }
    dfs(0);
    rdfs(n-1);

    rep(i, n) ok[i] = reachableFrom1[i]&reachableToN[i];

    vector<int> d(n, INF);
    d[0] = 0;
    bool upd = true;

    int step = 0;
    while(upd){
        upd = false;
        rep(i, m){
            int a,b,c;
            //tuple unpack
            tie(a, b, c) = edges[i];
            if (!ok[a]) continue;
            if (!ok[b]) continue;
            int newD = d[a] + c;
            if (newD < d[b]){
                upd = true;
                d[b] = newD;
            }
        }
        step++;
        if (step > n){
            puts("-1");
            return 0;
        }
    }
    int ans = -d[n-1];

    cout << max(0, ans) << endl;

}

