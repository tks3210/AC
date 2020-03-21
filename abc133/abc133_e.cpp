#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;
long mod = 1000000007;
/* C++の構造体 メンバがpublicなclass */
typedef struct mint
{
    ll x;
    mint(ll x = 0) : x(x % mod) {} //コンストラクタ
    /* 演算子オーバーロード */
    mint &operator+=(const mint a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        if ((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const
    {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const
    {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const
    {
        mint res(*this);
        return res *= a;
    }
    mint pow(ll t) const
    {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const
    {
        return pow(mod - 2);
    }
    mint &operator/=(const mint a)
    {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const
    {
        mint res(*this);
        return res /= a;
    }
} mint_t;

mint ans = 0;
vector<vector<int>> graph;
int k;
void dfs(int now, int parent){
    int color_rem = k;
    int child_size = graph[now].size();
    if (parent == -1){
        color_rem -= 1;
    } else {
        color_rem -= 2;
        child_size -= 1;
    }
//    cout << now << ":" << color_rem<< endl;
    if (color_rem < child_size){
        ans *= 0;
    } else {
        rep(i, child_size) {ans *= color_rem-i;}
    }
    for(auto next: graph[now]){
        if (next == parent) continue;
        dfs(next, now);
    }
    return;
}

int main()
{
    int n;cin >> n >> k;
    graph = vector<vector<int>>(n);
    rep(i, n - 1){ 
        int a, b; cin>>a>>b;a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ans = k;    
    dfs(0, -1);
    cout << ans.x << endl;
}

