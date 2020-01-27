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
int color[N_OVERSIZE] = {0}; //white 1, black -1


void dfs(int parent, int now, int now_color){
    if (root[now].size() == 1 && now != 0){
        return;        
    } 
    for (auto node : root[now])
    {
        if (node.first != parent){
            if (node.second%2 == 0){
                color[node.first] = now_color;
            } else {
                color[node.first] = -now_color;
            }
            dfs(now, node.first, color[node.first]);
        }
    }

}

int main()
{
    int n;
    cin >> n;
    rep(i, n -1){ 
        int tmpu, tmpv, tmpw; 
        cin >> tmpu >> tmpv >> tmpw;
        tmpu--; tmpv--; 
        root[tmpu].push_back(P(tmpv, tmpw));
        root[tmpv].push_back(P(tmpu, tmpw));
    }

    color[0] = -1;
    dfs(-1, 0, -1); //white_start

    rep(i, n){
        cout << (color[i] == 1 ? 1: 0) << endl;
    }

}

