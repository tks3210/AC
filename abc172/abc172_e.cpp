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

ll intpow(mint_t m, int n)
{
    if (n == 0) return 1;
    mint_t ans(1);
    while (n >= 1)
    {
        if ((n % 2) == 0){
            m *= m.x;
            n /= 2;
        }else {
            ans *= m.x;
            n -= 1;
        }
    }
    return ans.x;
}

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

int main()
{
    ll n, m;
    cin >> n >> m;

    //自分と被っていない子を求める
    mint all(1);
    int tmp = m;
    rep(i, n){
        all *= tmp;
        tmp--;
    }

    combination cb(m);

    mint ans(0);
    rep1(i, n){
        mint score = cb(n, i);
        score *= cb.fact[m-i];
        score /= cb.fact[m-n];
        if (i%2) ans+=score;
        else ans-=score;
    }
    ans-=1;
    mint ans_fin = all-1 - ans; //被ってない子
    ans_fin *= all;
    
    cout << ans_fin.x << endl;
}

