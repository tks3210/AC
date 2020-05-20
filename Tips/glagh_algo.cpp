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

/* input info */
P graph[] = {
    {0, 1},
    {1, 2},
    {3, 1},
    {3, 4},
    {4, 5},
    {1, 5},
    {5, 2},
    {2, 4},
}; //グラフ
int m = sizeof(graph) / sizeof(graph[0]);
int n = 6; //頂点数
#define N_MAX 20

/* graph */
vector<vector<int>> root(N_MAX);


// 入次数を用いるアルゴリズム
vector<int> in_num(N_MAX, 0);
bool tsort_in(vector<int>& ans){
    queue<int> q;
    rep(i, n){
        for(int next: root[i]){
            in_num[next]++;
        }
    }
    //show(in_num);
    //入次数0の頂点をpush
    rep(i, n){
        if (in_num[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front(); q.pop();
        ans.push_back(node);
        for(int next : root[node]){
            in_num[next]--;
            if (in_num[next] == 0) q.push(next);
        }
    }
    if (ans.size() == n){
        return true;
    } else {
        return false;
    }
}


// dfs を用いるアルゴリズム

enum {
    NONE,
    NON_COMPLETED,
    COMPLETED,
} state_t;//閉路検出用

vector<int> visited(N_MAX);
int dfs(int v, vector<int> &ans){
    if (visited[v] == COMPLETED) return 0;
    if (visited[v] == NON_COMPLETED) return -1;
    visited[v] = NON_COMPLETED;
    for(int next: root[v]){
        if (dfs(next, ans) == -1){
            return -1;
        }
    }
    visited[v] = COMPLETED;
    ans.push_back(v);
    return 0;
}
bool tsort_dfs(vector<int> &ans){
    rep(i, n){
        if (visited[i] == NONE) {
            if (dfs(i, ans) == -1){
                return false;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return true;
}


int main(void){

    rep(i, m){
        root[graph[i].first].push_back(graph[i].second);    
    }
        
    vector<int> ans1, ans2;
    if(!tsort_in(ans1)){
        printf("loop exist!");
    }

    show(ans1);

    if(!tsort_dfs(ans2)){
        printf("loop exists!");
    }

    show(ans2);


    return 0;
}