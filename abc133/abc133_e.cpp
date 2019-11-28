#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

typedef long long ll;
ll mod = 1000000007;

ll dfs(int k, const vector<vector<int>>&graph, int now, int from){
    int color_var;
    if(from == -1){
        color_var = k - 1;
    } else {
        color_var = k - 2;
    }
    if (graph[now].size() > k){
        return 0;
    }

    for (int i = 0; i < graph[now].size(); i++)
    {
        if (graph[now][i] == from) continue;
        dfs(1, graph, graph[now][i], now);
    }
}

int main()
{
    int n, k;cin >> n >> k;
    vector<vector<int>> graph(n);
    rep(i, n - 1){ 
        int a, b; cin>>a>>b;a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }    
    dfs(1, graph, 0, -1);
}

