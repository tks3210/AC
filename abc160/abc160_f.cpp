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


const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const {
    mint res(*this);
    return res+=a;
  }
  mint operator-(const mint a) const {
    mint res(*this);
    return res-=a;
  }
  mint operator*(const mint a) const {
    mint res(*this);
    return res*=a;
  }
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const {
    return pow(mod-2);
  }
  mint& operator/=(const mint a) {
    return (*this) *= a.inv();
  }
  mint operator/(const mint a) const {
    mint res(*this);
    return res/=a;
  }
};

struct combination {
  vector<mint> fact, ifact;
  combination(int n):fact(n+1),ifact(n+1) {
    assert(n < mod);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
    ifact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
  }
  mint operator()(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n]*ifact[k]*ifact[n-k];
  }
};


const int MAX_N = 200050;
vector<int> to[MAX_N];
combination cb(MAX_N);

struct DP {
    mint dp; //pattern数
    int t; //部分木の大きさ
    DP(mint dp=1, int t=0):dp(dp),t(t) {}
    //木dpの汎用的な処理(&付く、付かないの違いが分からん)　
    DP& operator+=(const DP& a){
        dp*=a.dp;
        dp*=cb(t+a.t, t);
        t += a.t;
        return *this;
    } 
    DP operator-(const DP& a) const {
        DP res(*this);
        res.t -= a.t;
        res.dp /= cb(res.t + a.t, res.t);
        res.dp /= a.dp;
        return res;
    } 
    DP addroot() const {
        DP res(*this);
        res.t++;
        return res;
    }
};

// dp[i]の値が答え(iを始点としたときのパターン数)となる
DP dp[MAX_N];

// dfs(0)の処理によって
// dp[i]の値に、子要素のパターン数の合計を足し合わせている。
// これにより、dp[0]は正しく求まっているが、
// dp[1]以下の子要素は親側を部分木としたときのパターン数を足せていない状態。
// =>親側を部分木としたときのパターン数を求める必要がある。これをbfsで行う

void dfs(int v, int p = -1){
    for (int u : to[v]){
        if (u == p) continue;
        dfs(u,v);
        dp[v] += dp[u].addroot();
    }
}

// 親側を部分木としたパターン数は、
// ①親を始点としたパターン数 - ②子(自分)を始点とした子要素側のパターン数で求まる
// 親側から探索したとき(別にbfsでなくてもよい)、①は既に求まっている状態で、②もdp[u]の値がそうなっているので、
// dp[v] - dp[u].addrootにより求まる。(親ノードを数えられてないので、これにaddrootが必要)

void bfs(int v, int p = -1){
    for (int u : to[v]){
        if (u == p) continue;
        DP d = dp[v] - dp[u].addroot();
        dp[u] += d.addroot();
        bfs(u, v);
    }
}

int main()
{
    int n;
    cin >> n;
    rep(i, n-1){ 
        int tmpa, tmpb; cin >> tmpa >> tmpb;
        tmpa--; tmpb--;
        to[tmpa].push_back(tmpb);        
        to[tmpb].push_back(tmpa);        
    }

    dfs(0);
    bfs(0);
    rep(i, n){
        cout << dp[i].addroot().dp.x << endl;
    }
    return 0;
}

/*
木dpを行うと、dp[parent][child]の値が再利用できる

9C2 * 7C2 * 5C5 = 9! / 2! 2! 5!と置ける

"部分木"と"根に向かう辺"で情報を管理すると、O(N)でできる
　子に向かう辺の情報はdfs,親に向かう辺の情報はbfs
　計算にO(d) d:次数かかるので、bfs時の導出は、総和から引くことで計算量を壊さないようにする

*/