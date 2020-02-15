#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;

const int MAX_N = 1005;
const int MAX_V = MAX_N * MAX_N / 2;
int id[MAX_N][MAX_N] = {0};
vector<int> to[MAX_V];
int toId(int i, int j){
    if (i > j) swap(i, j);
    return id[i][j];
}

bool visited[MAX_V];
bool calculated[MAX_V];
int dp[MAX_V]; // max length

int dfs(int v) {
    if (visited[v]) {
        if (calculated[v]) return dp[v];
        else return -1;
    }
    visited[v] = true;
    dp[v] = 1;
    for (int u: to[v]){
        int res = dfs(u);
        if (res == -1) return -1;
        dp[v] = max(dp[v], res + 1);
    }
    calculated[v] = true;
    return dp[v];
}


int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>()); 
    rep(i, n){
        rep(j, n-1){
            int tmp; cin >> tmp;
            tmp--;
            a[i].push_back(tmp);
        }
    }
    int V = 0;
    rep(i, n)rep(j, n){
        if (i < j) id[i][j] = V++;
    }
    rep(i, n){
        rep(j, n-1){
            a[i][j] = toId(i, a[i][j]);
        }
        rep(j, n-2){
            to[a[i][j+1]].push_back(a[i][j]);
        }
    }
    int ans = 0;
    rep(i, V){
        int res = dfs(i);
        if (res == -1){
            puts("-1");
            return 0;
        }
        ans = max(ans, dfs(i));
    }

    cout << ans << endl;
}

