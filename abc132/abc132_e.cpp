#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;

int step[300500] = {0};

void bfs(int s, vector<vector<int>>& line){

    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int now = q.front();
        for (auto next: line[now])
        {
            if (step[next] != 0) continue;
            q.push(next);
            step[next] = step[now] + 1;
        }
        q.pop();
    }

}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> line(3*n);
    rep(i, m){ 
        int tmp_u, tmp_v; 
        cin >> tmp_u >> tmp_v; 
        tmp_u--; tmp_v--;
        line[tmp_u].push_back(tmp_v + n);
        line[tmp_u + n].push_back(tmp_v + (n*2));
        line[tmp_u + (n*2)].push_back(tmp_v);

    }
    int s, t;
    cin >> s >> t;
    s--; t--;
    step[s] = 1;
    bfs(s, line);
    // rep(i, 3*n){
    //     cout << i << " " << step[i] << endl;
    // }
    if (step[t]%3 == 1){
        cout << step[t]/3 << endl;
    } else {
        cout << "-1" << endl;
    }
}

