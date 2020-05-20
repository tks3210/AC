#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1e18
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

/*

状態が頂点と時間だけであれば、最小時間を求めるダイクストラ法だが、、、？

今回状態として、時間、銀貨、頂点の場所が存在する。
推移条件は　
移動：v -> u  s -= A, time += B
両替：v -> v  s += C, time += D

状態を
dp[v][s]: 頂点v, 所持金sにおける時間とする
sは10^9まであると思われがちだが、実はs <= N*運賃Aの最大値として問題ない。

また、状態が二次元になっただけで、
推移の中で議論する値timeが減少するような推移は存在しないのでダイクストラ法は使用できる。
*/

struct Edge {
    int to;
    int a;
    ll b;
    Edge(int to, int a, ll b): to(to), a(a), b(b) {}
};
struct Chg {
    ll c;
    ll d;
    Chg(ll c, ll d) : c(c), d(d) {}
};
struct Data {
    int v;
    ll coin;
    ll time;
    Data(int v, ll coin, ll time):  v(v), coin(coin), time(time) {}
    bool operator<(const Data& a) const {
        return time>a.time;
    }
};
const int n_max = 55;
const int a_max = 55;
vector<Edge> root[n_max];
vector<Chg> exc;
const int coin_limit = n_max*a_max;
//vector<vector<ll>> dp(n_max, vector<ll>(coin_limit, INF));
ll dp[n_max][coin_limit] = {0};

void dijkstra(int top, int s, map<int, ll> &ans){
    rep(i, n_max)rep(j, coin_limit){
        dp[i][j] = INF;
    }
    priority_queue<Data> pq;
    auto push = [&](int v, int coin, ll time){
        if (dp[v][coin] < time) return;
        dp[v][coin] = time;
        pq.emplace(v, coin, time);
    };
    push(top, s, 0);
    set<int> node;
    while(!pq.empty()){
        auto now = pq.top(); pq.pop();
        for (auto next: root[now.v]){
            int remain = now.coin - next.a;
            ll time = now.time + next.b;
            if (remain < 0) continue;
            if (dp[next.to][remain] <= time) continue;
            push(next.to, remain, time);
        }
        int r = now.coin + exc[now.v].c;
        r = min(r, coin_limit);
        ll t = now.time + exc[now.v].d;
        if (dp[now.v][r] > t){
            push(now.v, r, t);
        }

//        cout << now.v << ":" << now.coin  << ":" << now.time << endl; 

        if (ans.find(now.v) == ans.end()){
            ans.insert({now.v, now.time});
        }
    }

}

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    rep(i, m){
        int u,v,a;
        ll b;
        cin >> u >> v >> a >> b;
        u--; v--;
        root[u].emplace_back(v,a,b);
        root[v].emplace_back(u,a,b);
    }
    rep(i, n){
        ll c, d;
        cin >> c >> d;
        exc.emplace_back(c, d);
    }

    map<int, ll> ans;
    dijkstra(0, min(s, coin_limit), ans);

    rep(i, n){
        if (i==0) continue;
        // ll ans1 = INF;
        // rep(j, coin_limit){
        //     ans1 = min(ans1, dp[i][j]);
        // }
        // cout << ans1 << endl;
        cout << ans[i] << endl;
    }

}

