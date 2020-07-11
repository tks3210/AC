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


typedef int FLOW;                // フローを表す型、今回は int 型
const int MAX_V = 210;           // グラフの最大ノード数
const FLOW INF = 100000000;      // 十分大きい値

// グラフの辺の構造体
struct Edge {
    int rev, from, to;
    FLOW cap, icap;
    Edge(int r, int f, int t, FLOW c) : rev(r), from(f), to(t), cap(c), icap(c) {}
    friend ostream& operator << (ostream& s, const Edge& E) {
        if (E.cap > 0) return s << E.from << "->" << E.to << '(' << E.cap << ')';
        else return s;
    }
};

// グラフ構造体
struct Graph {
    int V;
    vector<Edge> list[MAX_V];

    Graph(int n = 0) : V(n) { for (int i = 0; i < MAX_V; ++i) list[i].clear(); }
    void init(int n = 0) { V = n; for (int i = 0; i < MAX_V; ++i) list[i].clear(); }
    void resize(int n = 0) { V = n; }
    void reset() { for (int i = 0; i < V; ++i) for (int j = 0; j < list[i].size(); ++j) list[i][j].cap = list[i][j].icap; }
    inline vector<Edge>& operator [] (int i) { return list[i]; }

    Edge &redge(Edge e) {
        if (e.from != e.to) return list[e.to][e.rev];
        else return list[e.to][e.rev + 1];
    }

    void addedge(int from, int to, FLOW cap) {
        list[from].push_back(Edge((int)list[to].size(), from, to, cap));
        list[to].push_back(Edge((int)list[from].size() - 1, to, from, 0));
    }
};

// 最大流を求めるサブルーチンたち
static int level[MAX_V];
static int iter[MAX_V];

void dibfs(Graph &G, int s) {
    for (int i = 0; i < MAX_V; ++i) level[i] = -1;
    level[s] = 0;
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int i = 0; i < G[v].size(); ++i) {
            Edge &e = G[v][i];
            if (level[e.to] < 0 && e.cap > 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

FLOW didfs(Graph &G, int v, int t, FLOW f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); ++i) {
        Edge &e = G[v][i], &re = G.redge(e);
        if (level[v] < level[e.to] && e.cap > 0) {
            FLOW d = didfs(G, e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                re.cap += d;
                return d;
            }
        }
    }
    return 0;
}

// 最大流を求めるメイン関数
FLOW Dinic(Graph &G, int s, int t) {
    FLOW res = 0;
    while (true) {
        dibfs(G, s);
        if (level[t] < 0) return res;
        memset(iter, 0, sizeof(iter));
        FLOW flow;
        while ((flow = didfs(G, s, t, INF)) > 0) {
            res += flow;
        }
    }
}

int main()
{
    int n;

    cin >> n;
    vector<P> rp(n), bp(n);

    rep(i, n){ cin >> rp[i].first >> rp[i].second;}
    rep(i, n){ cin >> bp[i].first >> bp[i].second;}

    Graph G(n+n+2);

    int s_node = n+n;
    int t_node = n+n+1;

    rep(i, n){
        rep(j, n){
            if (rp[i].first <= bp[j].first && rp[i].second <= bp[j].second){
                G.addedge(i, j+n, 1);
            }
        }
    }

    rep(i, n) G.addedge(s_node, i, 1);
    rep(i, n) G.addedge(i+n, t_node, 1);

    FLOW ans = Dinic(G, s_node, t_node);
    cout << ans << endl;

}

