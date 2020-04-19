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
vector<int> node[MAX_N];
combination cb(MAX_N);

typedef struct {
    mint pat;
    int node;
} c_info_t;

//親nodeはpattern数とnode数を受け取る必要がある
c_info_t dfs(int now, int parent){
    //
    vector<c_info_t> child;
    int node_all = 0;
    for(auto next: node[now]){ 
        if (next == parent) continue;
        c_info_t tmp = dfs(next, now);
        node_all += tmp.node;
        child.push_back(tmp);
    }
    mint pat(1);
    int node_tmp = node_all;
    rep(i, child.size()){
        pat *= child[i].pat;
        pat *= cb(node_tmp, child[i].node);
        node_tmp -= child[i].node;
    }
    node_all++;
//    printf("%d %d: %lld:%d\n",now+1, parent+1, pat.x, node_all);

    return {pat, node_all};
}

int main()
{
    int n;
    cin >> n;
    rep(i, n-1){ 
        int tmpa, tmpb; cin >> tmpa >> tmpb;
        tmpa--; tmpb--;
        node[tmpa].push_back(tmpb);        
        node[tmpb].push_back(tmpa);        

    }

    rep(i, n){
        cout << dfs(i, -1).pat.x << endl;
    }
//    cout << dfs(1, -1).pat.x << endl;
}

/*
木dpを行うと、dp[parent][child]の値が再利用できる

9C2 * 7C2 * 5C5 = 9! / 2! 2! 5!と置ける

"部分木"と"根に向かう辺"で情報を管理すると、O(N)でできる
　子に向かう辺の情報はdfs,親に向かう辺の情報はbfs
　計算にO(d) d:次数かかるので、bfs時の導出は、総和から引くことで計算量を壊さないようにする

*/