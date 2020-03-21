#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1001001001
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


#define MAP_MAX 55
//0を通れないとする
int s[MAP_MAX][MAP_MAX];

vector<vector<int>> len(MAP_MAX, vector<int>(MAP_MAX, INF));
P root[4] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

int h, w;
int bfs(){
    len[1][1] = 0;
    queue<P> q;
    q.push({1,1});

    while(!q.empty()){
        auto now = q.front(); q.pop();
        rep(i,4){
            P next = {now.first + root[i].first, now.second + root[i].second};
            if (s[next.first][next.second] && len[next.first][next.second]==INF){
                len[next.first][next.second] = len[now.first][now.second] + 1;
                q.push(next);
            }
        }
    }
    return len[h][w];
}

int main()
{
    cin >> h >> w;
    int _ans=0;
    rep(i,h)rep(j,w){
        char tmp; cin >> tmp;
        if (tmp == '.') {s[i+1][j+1] = 1; _ans++;}
    }

    int ans = bfs();
    // rep(i,h+2){
    //     rep(j,w+2){
    //     cout << len[i][j] << ":";
    //     }
    //     cout << endl;
    // }
    if(ans==INF) cout << -1 << endl;
    else cout << _ans-(ans+1) << endl;

}

