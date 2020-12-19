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
typedef tuple<ll, ll, ll> T3;
ll gcd(ll x, ll y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}

/*
仲が悪いペアを含む場合の数え上げ
余事象/包除原理


各イワシにラベルを付ける
A=3 B=6 => 1/2
A=-4 B=9 => -4/9
A=0 B=5 => 0
A=3 B=0 => 1e18+1
A=0 B=0 => 1e18+2


*/


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

int seihu(ll x, ll y){
    if (x == 0 || y == 0) return -1;
    if (x > 0 && y < 0) return -1;
    if (x < 0 && y > 0) return -1;
    return 1;
}


int main()
{
    int n;
    cin >> n;
    vector<llP> a(n);
    rep(i, n){ cin >> a[i].first >> a[i].second; }
    int zero = 0;
    int azero = 0;
    int bzero = 0;
    map<T3, ll> iwashi;
    rep(i, n){
        if (a[i].first == 0 && a[i].second == 0){
            zero++;
            continue;
        } else if (a[i].second == 0){
            iwashi[make_tuple(1, 1, 0)]++;
            continue;
        } else if (a[i].first == 0){
            iwashi[make_tuple(-1, 0, 1)]++;
            continue;
        } else {
            ll div = gcd(abs(a[i].first), abs(a[i].second));
            ll sgn = seihu(a[i].first, a[i].second);
            iwashi[make_tuple(sgn, abs(a[i].first)/div, abs(a[i].second)/div)]++;
        }
    }
    mint ans = 1;
    for (auto now:iwashi)
    {
        T3 t = now.first;
        if (iwashi[t] == 0) continue;
        int sgn = get<0>(t);
        ll a = get<1>(t);
        ll b = get<2>(t);

        T3 tpair = make_tuple(-sgn, b, a);
        ans *= intpow(2, iwashi[t]) + intpow(2, iwashi[tpair]) - 1;
        iwashi[tpair] = 0;
    }
    ans += zero;
    ans -= 1;
    cout << ans.x << endl;
   
}

