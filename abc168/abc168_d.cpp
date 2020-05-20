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

#define INF 10000000
const int n_max = 100050;
vector<vector<int>> root(n_max);
vector<int> dist(n_max, INF);
vector<int> from(n_max);


void bfs(int st){
    queue<int> q;
    q.push(st);
    dist[st] = 0;

    while(!q.empty()){
        int now = q.front(); q.pop();
        for(auto next : root[now]){
            if (dist[next] != INF) continue; //既に探索
            q.push(next);
            dist[next] = dist[now]+1;
            from[next] = now+1;
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b; a--; b--;
        root[a].push_back(b);
        root[b].push_back(a);
    }
    
    bfs(0);

    bool isok = true;
    for (int i = 1; i < n; i++)
    {
        if (dist[i] == INF) isok = false;
    }
    if (!isok){
        cout << "No"  << endl;
        return 0;
    } else {
        cout << "Yes" << endl;
    }

    for (int i = 1; i < n; i++)
    {
        cout << from[i] << endl;
    }
    return 0;
}

