#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}

const int n_max = 1050;
int masu[n_max][n_max] = {0};
const int offset = 5;

void dfs01(P st){

    vector<P> walk, warp;

    for (int i = -2; i <= 2; i++)
    {
        for (int j = -2; j <= 2; j++)
        {
            if (i == 0 && j == 0) continue;
            if (abs(i) + abs(j) == 1) walk.emplace_back(i, j);
            else warp.emplace_back(i, j);
        }
    }
    
    deque<P> q;
    q.push_back(st);
    masu[st.first+offset][st.second+offset] = 1;
    while(!q.empty()){
        P now = q.front(); q.pop_front();
        int nx = now.first;
        int ny = now.second;
        rep(i, walk.size()){
            P next = {nx + walk[i].first, ny + walk[i].second};
            int nex = next.first;
            int ney = next.second;
            if (masu[nex+offset][ney+offset] != -1){
                if (chmin(masu[nex+offset][ney+offset], masu[nx+offset][ny+offset])) q.push_front(next);
            }
        }
        rep(i, warp.size()){
            P next = {nx + warp[i].first, ny + warp[i].second};
            int nex = next.first;
            int ney = next.second;
            if (masu[nex+offset][ney+offset] != -1){
                if (chmin(masu[nex+offset][ney+offset], masu[nx+offset][ny+offset]+1)) q.push_back(next);
            }
        }
    }
}

int main()
{
    int h, w;
    cin >> h >> w;
    P st, end;
    cin >> st.first >> st.second;
    cin >> end.first >> end.second;
    st.first--; st.second--;
    end.first--; end.second--;

    const int l_max = 1000000;
    rep(i, n_max)rep(j, n_max) masu[i][j] = -1;
    rep(i, h)rep(j, w){
        char t; cin >> t;
        if (t != '#') masu[i+offset][j+offset] = l_max;
    }
    dfs01(st);

    int ex = end.first + offset;
    int ey = end.second + offset;
    if (masu[ex][ey] == l_max){
        cout << "-1" << endl;
    } else {
        cout << masu[ex][ey] - 1 << endl;
    }

}

