#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout << endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

const int MAX_N = 1005;
vector<int> node[MAX_N]; 
bool visited[MAX_N];
bool completed[MAX_N];
int n;

bool bfs(int v, vector<int> &min_loop){

    queue<int> que;
    vector<int> step(n, -1); //距離を
    vector<int> pre(n, -1); //逆経路用に確保
    step[v] = 0;
    que.push(v);
    while(!que.empty()){
        int now = que.front(); que.pop();
        for (auto next: node[now]){
            if (step[next] != -1) continue;
            step[next] = step[now] + 1;
            pre[next] = now;
            que.push(next);
        }

    }

//    show(step);
    int ans = MOD;
    int min_v = -1;
    for (int t = 0; t < n; t++)
    {
        if (t == v || step[t] == -1) continue;
        for(auto next: node[t]){
            if (next == v) {
                ans = min(ans, step[t] + 1);
                min_v = t;
            }
        }
    }
    if (ans == MOD){
        return false;
    } else {
        while(min_v != v) {min_loop.push_back(min_v); min_v = pre[min_v];}
        min_loop.push_back(v);
        return true;
    }

}

int main()
{
    int m;
    cin >> n >> m;
    rep(i, m){ 
        int tmpa, tmpb; cin >> tmpa >> tmpb;
        tmpa--; tmpb--;
        node[tmpa].push_back(tmpb);        
    }
   //rep(i, n)    show(node[i]);

    bool loop = false;
    vector<int> ans_loop(n+1);
    vector<int> min_loop;

    rep(i,n){
        min_loop = vector<int>();
        if (bfs(i, min_loop)){
//            cout << i <<  ":";
//            show(min_loop);
            if (min_loop.size() < ans_loop.size()){
                ans_loop = min_loop;
            }
            loop = true;
        }
    }
    if(loop){
        cout << ans_loop.size() << endl;
        rep(i, ans_loop.size()) cout << ans_loop[i] + 1 << endl; 
    } else {
        puts("-1");
    }
    return 0;
}

