#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int cnt[200001] = {0};
int anscnt[200001] = {0};

int dfs(int score, const vector<vector<int>>&graph, int now, int from){

    int nextscore;
    anscnt[now] = score + cnt[now];
    for (int i = 0; i < graph[now].size(); i++)
    {
        if (graph[now][i] == from) continue;
        dfs(anscnt[now], graph, graph[now][i], now);
    }
}

int main()
{
    int n, q;cin >> n >> q;
    vector<vector<int>> graph(n+1);
    rep(i, n - 1){ 
        int a, b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }    
    rep(i, q){
        int p, x; cin>>p>>x;
        cnt[p] += x;
    }
    dfs(0, graph, 1, -1);

    rep(i, n){
        cout << anscnt[i + 1] << " ";
    }
    cout << endl;
}
