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


/*
全方位木DP

N個の頂点を持つ木に1~Nの数字を書く場合のパターン数を求める
* 頂点kに1を書く。
* 既に数字を書かれている頂点と隣接している頂点から2以降の数字を書いていく。
頂点kごとにパターン数を出力する。(1<=N<=2*10^5)

頂点kを固定とし、k=1の場合単体をO(N)で求める方法を考える

子を頂点とする部分木の頂点の総和をAx, パターン数をBxとすると、
親を頂点とする部分木の頂点の総和は、A1 + A2 + ... + An + 1
親を頂点とする部分木のパターン数は、B1 * B2 * ... * Bn * (S)
  S = (A1 + A2 + ... An)! / (A1! * A2! * ... * An!)
で求めることができるので、子⇒親方向へと計算すると求めることができる。

この計算を全てのkで行うとO(N^2)となり間に合わない。
よってこの計算結果を、k=2~Nの場合に置いても流用する必要がある。。。

計算の手順は
１．頂点1をrootとするパターン数をdfsにより求める。このとき、各頂点の子側の部分木をDPに保存しておく。
　　　このときDPの値としては、頂点1のみ正しい答えが求まっているが、
　　　頂点1以外においては親側の部分木の評価を行う必要がある。
２．再度頂点1から探索するが、このとき行きがけ順で下記の処理を行う。
　　　a. 親側の頂点のパターン数から、自分の部分木が存在しないときのパターン数を求める。
　　　b. その後、そのパターン数を元にDPに足し合わせる。

パターン数の結合と分解を各探索で繰り返すので、
パターン数を扱うデータ構造DPの演算子を別途定義すると、計算が高速化できる。

*/

const int MAX_N = 200050;
vector<int> root[MAX_N];
combination cb(MAX_N);

struct DP{
  mint pat;
  int t;
  DP (mint pat=1, int t=0) : pat(pat), t(t){}
  DP& operator+=(const DP& a){
    t += a.t;
    pat *= a.pat;
    pat *= cb(t, a.t);
    return *this;
  }
  DP operator-(const DP& a) const {
    DP tmp = *this;
    tmp.pat /= a.pat;
    tmp.pat /= cb(tmp.t, a.t);
    tmp.t -= a.t;
    return tmp;
  }
  DP addroot() const {
    DP tmp = *this;
    tmp.t++;
    return tmp;
  }

};

DP dp[MAX_N];

DP dfs(int v, int parent){
  
  DP ans;
  for(auto next : root[v]){
    if (next != parent){
      ans += dfs(next, v);
    }
  }

  //cout << v << endl;
  //cout << ans.pat.x << ";" << ans.t << endl;
  dp[v] = ans;
  return ans.addroot();
}


DP dfs_inv(int v, int parent){
  for(auto next : root[v]){
    if (next != parent){
      //parentのスコアから自分を引いた数を求める
      // cout << v << ":::"<<endl;
      // cout << dp[v].pat.x << ":"<< dp[v].t << endl;
      // cout << dp[next].pat.x << ":" << dp[next].t << endl;
      DP tmp = dp[v] - dp[next].addroot();
      // cout << tmp.pat.x << ":" << tmp.t << endl;
      // cout << endl;


      dp[next] += tmp.addroot();
      dfs_inv(next, v);
    }
  }
}


int main(){
  int n; cin >> n;
  vector<P> ab(n);
  rep(i, n-1) cin >> ab[i].first >> ab[i].second;

  rep(i, n-1) {
    root[ab[i].first-1].push_back(ab[i].second-1);
    root[ab[i].second-1].push_back(ab[i].first-1);
  }

  dfs(0, -1);
  // rep(i, n){
  //   cout << dp[i].pat.x << ":" << dp[i].t <<endl;
  // }
  dfs_inv(0, -1);

  rep(i, n){
    //cout << dp[i].pat.x << ":" << dp[i].t << endl;
    cout << dp[i].pat.x << endl;
  }

}
