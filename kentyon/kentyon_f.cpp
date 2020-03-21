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

const int MAP_MAX = 510;
int r_map[MAP_MAX][MAP_MAX]={0};

vector<vector<int>> len(MAP_MAX, vector<int>(MAP_MAX, INF));
P root[4] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};

int main()
{
    int h,w;
    cin >> h >> w;
    
    P st, go;
    rep1(i, h){
        rep1(j, w){
            char c; cin >> c;
            if (c == 's'){
                st.first = i; st.second = j;
            } else if (c == 'g'){
                go.first = i; go.second = j;
                r_map[i][j] = 1;
            } else if (c == '.'){
                r_map[i][j] = 1;
            } else {
                r_map[i][j] = 2;
            }
        }
    }

    deque<P> dq;
    dq.push_front(st);
    len[st.first][st.second]=1;
    while(!dq.empty()){
        auto now = dq.back(); dq.pop_back();
        rep(i,4){
            P next = {now.first + root[i].first, now.second + root[i].second};
            //cout << next.first << ":" << next.second << endl;
            if (len[next.first][next.second]==INF && r_map[next.first][next.second]){
                if (r_map[next.first][next.second]==1){
                    len[next.first][next.second] = len[now.first][now.second];
                    dq.push_back(next);
                }else{
                    len[next.first][next.second] = len[now.first][now.second]+1;
                    dq.push_front(next);
                }
            }
        }
    }

    // rep(i,h+2){
    //     rep(j,w+2){
    //     cout << ((len[i][j]==INF) ? 0 : len[i][j]) << ":";
    //     }
    //     cout << endl;
    // }
    if(len[go.first][go.second]<=3) cout << "YES" << endl;
    else cout << "NO" << endl;
}

