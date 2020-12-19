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



struct maze{
    vector<vector<ll>> _maze;
    const int wall = -1;
    const int nostep = 1e9;
    int _r = 0;
    int _c = 0;
    int _offset = 0;

    maze(int r, int c, int offset = 0){
        _offset = offset;
        _maze.assign(r+_offset*2, vector<ll>(c+_offset*2, wall));
        _r = r;
        _c = c;
        rep(i, _r)rep(j, _c){
            char tmp; cin >> tmp;
            if (tmp == '#') _maze[i+_offset][j+_offset] = wall;
            else _maze[i+_offset][j+_offset] = nostep;
        }
    }

    ll get(int r, int c){
        return _maze[r+_offset][c+_offset];
    }

    ll get(P rc){
        return _maze[rc.first+_offset][rc.second+_offset];
    }

    void set(int r, int c, ll val){
        _maze[r+_offset][c+_offset] = val;
    }

    void set(P rc, int val){
        _maze[rc.first+_offset][rc.second+_offset] = val;
    }

    bool chmin(int r, int c, ll val){
        if (_maze[r+_offset][c+_offset] > val){ _maze[r+_offset][c+_offset] = val; return true;}
        else return false;
    }

    bool chmin(P rc, ll val){
        if (_maze[rc.first+_offset][rc.second+_offset] > val){ _maze[rc.first+_offset][rc.second+_offset] = val; return true;}
        else return false;
    }

    void showmaze(){
        rep(i, _r){
            rep(j, _c){
                if (get(i,j) == nostep) cout << " X";
                else if (get(i,j) == wall) cout << " #";
                else printf("%02lld", get(i,j));
            }
            cout << endl;
        } 
    }

};


int main()
{
    int r, c;
    int sy, sx, gy, gx;
    cin >> r >> c;
    cin >> sy >> sx >> gy >> gx;
    sy--; sx--;
    gy--; gx--;
    maze mz(r, c);

    queue<P> q;
    q.emplace(sy, sx);
    mz.set(P(sy,sx), 0);
    vector<P> walk{{1,0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!q.empty()){
        P now = q.front(); q.pop();
        rep(i, walk.size()){
            P next = {now.first + walk[i].first, now.second + walk[i].second};
            if (mz.get(next) == mz.nostep){
                //if (mz.chmin(next, mz.get(now)+1)) q.push(next);
                mz.set(next, mz.get(now)+1);
                q.push(next);
            }
        }        
    }
    //mz.showmaze();
    cout << mz.get(gy, gx) << endl;

}

