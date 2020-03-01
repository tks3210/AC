#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


const int V = 100005;
vector<int> to[V*2];
bool visited[V*2];

vector<int> cnt;
void dfs(int v){
    if (visited[v]) return;
    visited[v] = true;
    for(int u : to[v]) dfs(u);
    cnt[v/V]++;
    return;
}
int main(){
    int n;
    cin >> n;
    rep(i, n){
        int x, y;
        cin >> x >> y;
        y += V;
        to[x].push_back(y);
        to[y].push_back(x);
    }

    ll ans =0;
    rep(i, V*2){
        cnt = vector<int>(2); //再定義可能らしい
        dfs(i);
        ans += (ll)cnt[0]*cnt[1];
    }
    ans -= n;

    cout << ans << endl;
    return 0;
}