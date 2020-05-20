#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF MOD
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

//abc035_d

//重み付き辺を議論する場合のデータ管理
//dpの類題であるという意識
//

struct Edge{
    int to;
    ll min;
    Edge(int to, ll min) : to(to), min(min){} 
};
const int n_max = 100050;
vector<ll> dp(n_max, INF);

struct Data{
    int v;
    ll min;
    Data(int v, ll min) : v(v), min(min) {}
    bool operator< (const Data& a) const {
        return min > a.min;
    }
};

void dijkstra(int top, vector<Edge> *root){
    priority_queue<Data> pq;
    auto push = [&](int v, ll s){
        if (dp[v] < s) return;
        dp[v] = s;
        pq.emplace(v, s);
    };
    push(top,0);
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        ll min = now.min;
        int v = now.v;

        for(auto next: root[v]){
            if (dp[v] + next.min < dp[next.to]){
                push(next.to, dp[v]+next.min);
            }
        }
    }
}



int main(){
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n);
    vector<Edge> root[n];
    vector<Edge> root_inv[n];


    rep(i, n) {cin >> a[i];}
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        root[a].emplace_back(b, c);
        root_inv[b].emplace_back(a, c);
    }

    dijkstra(0, root);
    auto dp1 = dp;

    dp = vector<ll> (n_max, INF);

    dijkstra(0, root_inv);
    auto dp2 = dp;

    ll ans = 0;
    rep(i, n){
        ll total = dp1[i] + dp2[i];
        if (total > t) continue;
        ll score = (t-total)*a[i];
        ans = max(ans, score);
    }    

    cout << ans << endl;


}
