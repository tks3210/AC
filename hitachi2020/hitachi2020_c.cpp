#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

const int node_max = 200050;
vector<int> graph[node_max];
int dist[node_max];
int ans[node_max];
bool visited[node_max];

void bfs(int v){

    queue<int> q;
    q.push(v);
    dist[v] = 0;

    while(!q.empty()){
        int now = q.front(); q.pop();
        for(auto next: graph[now]){
            if (visited[next]) continue;
            dist[next] = dist[now] + 1;
            q.push(next);
        }
        visited[now] = true;
    }
}

queue<int> num[3];
bool setdata(int i, int box){
    int res = 0;
    if (!num[box].empty()) {
        ans[i] = num[box].front(); 
        num[box].pop();
        return true;
    } else {
        return false;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<P> a(n-1);
    rep(i, n-1){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tmp1--; tmp2--;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }

    bfs(0);

    //rep(i, n) cout << dist[i] << endl;

    int gu = 0;
    int ki = 0;
    rep(i, n) {
        if(dist[i]%2==0) gu++;
        else ki++;
    }

    rep(i, n){
        int id = i+1;
        num[id%3].push(id);
    }

    // 11122200
    if (gu <= n/3){
        rep(i, n){
            if (dist[i]%2==0){
                setdata(i, 0);
            }else{
                setdata(i, 1) || setdata(i, 2) || setdata(i, 0);
            }
        }
    } else if (ki <= n/3){
        rep(i, n){
            if (dist[i]%2!=0){
                setdata(i, 0);
            }else{
                setdata(i, 1) || setdata(i, 2) || setdata(i, 0);
            }
        }
    } else {
        rep(i, n){
            if (dist[i]%2==0){
                setdata(i, 1) || setdata(i, 0);
            }else{
                setdata(i, 2) || setdata(i, 0);
            }
        }
    }

    rep(i, n){
        cout << ans[i]  << " ";
    }
}

