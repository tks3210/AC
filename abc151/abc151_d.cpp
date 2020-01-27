#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;
typedef pair<int, int> P;
#define INF 1000000000

int maze[22][22] = {0};
int maze_cnt[22][22] = {0};
int h, w;
int bfs(int x, int y, int step){
    int maxstep = 0;
    int nextstep[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    queue<pair<int, int>> point;
    
    if (maze[x][y] == 1) return 0;
    rep(i, 22)rep(j, 22){
        maze_cnt[i][j] = INF;
    }
    maze_cnt[x][y] = 0;
    point.push(P(x, y));

    int ans = 0;
    while(!point.empty()){
        P p = point.front();point.pop();
        for (int i = 0; i < 4; i++)
        {
            P newp = P(p.first + nextstep[i][0], p.second + nextstep[i][1]);
            if (newp.first != 0 && newp.first != w+1 && newp.second != 0 && newp.second != h+1){
                if (maze_cnt[newp.first][newp.second] == INF && maze[newp.first][newp.second] == 0){
                    maze_cnt[newp.first][newp.second] =  maze_cnt[p.first][p.second] + 1;
                    point.push(newp);
                    ans = max(ans,maze_cnt[newp.first][newp.second]);
                }                    
            }
        }
    }

    //cout << x << y << ":"<< ans << endl;
    return ans; 
}

int main()
{
    cin >> h >> w;
    rep(y, h)rep(x, w){
        char wall;
        cin >> wall;
        if (wall == '#'){
            maze[x+1][y+1] = 1;
        }
    }

    int ans = 0;
    rep(y, h)rep(x, w){
        int maxstep = bfs(x+1, y+1, 0);
        ans = max(ans, maxstep);
    }
    cout << ans << endl;
}

