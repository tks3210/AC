#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, ll> P;

#define N_OVERSIZE 100050
vector<P> root[N_OVERSIZE];
int color[N_OVERSIZE] = {0}; //white 0, black 1

void dfs(int v, int p){
    for (auto next: root[v]){
        if (next.first == p) continue;
        if (next.second % 2 == 0) color[next.first]=color[v];
        else color[next.first]=color[v]^1;
        dfs(next.first, v);
    }
    return;
}

bool visited[N_OVERSIZE];
void dfs_(int v){
    //if (root[v].size() == 1)
    visited[v] = true;
    for(auto next: root[v]){
        if (visited[next.first]) continue;
        dfs_(next.first);
        color[next.first] = 1;
    }
    return;
}

void dfs__(int v){
    visited[v] = true;
    for(auto next: root[v]){
        if (visited[next.first]) continue;
        if (next.second % 2 == 0) color[next.first]=color[v];
        else color[next.first]=color[v]^1;
        dfs__(next.first);
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    rep(i, n-1){ 
        int tmpu, tmpv, tmpw; 
        cin >> tmpu >> tmpv >> tmpw;
        tmpu--; tmpv--; 
        root[tmpu].push_back(P(tmpv, tmpw));
        root[tmpv].push_back(P(tmpu, tmpw));
    }

    color[0] = 0; //white_start

//    dfs_(0);
//    rep(i, n) cout << color[i] << endl;
    dfs__(0); 

    rep(i, n){
        cout << (color[i] == 1 ? 1: 0) << endl;
    }

}

