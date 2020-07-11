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
    int n, k;
    cin >> n >> k;
    vector<llP> a;
    rep(i, n){ 
        ll tmp; 
        cin >> tmp;
        ll m = 1;
        if (tmp < 0) m = -1;
        a.emplace_back(abs(tmp), m);
    }
    sort(a.begin(), a.end(), greater<llP>());
    ll minm = 1e10;
    ll minp = 1e10;
    int hugo = 0;
    mint mintk(1);
    rep(i, k){
        mintk *= a[i].first;
        if (a[i].second == 1) minp = min(a[i].first, minp);
        if (a[i].second == -1) {
            minm = min(a[i].first, minm);
            hugo++;
        }
    }
    //マイナスにせざるを得ない場合もケア
    ll maxm = 1e10;
    ll maxp = 1e10;
    for (int i = k; i < n; i++)
    {
        if (a[i].second == 1 && maxp == 1e10){
            maxp = a[i].first;
        } else if (a[i].second == -1 && maxm == 1e10){
            maxm = a[i].first;
        }
        if (maxp != 1e10 && maxm != 1e10) break;
    }
    
    if (hugo%2 != 0){
        if (k == n || (minp == 1e10 && maxp == 1e10)){
            mint mintk2(1);
            for (int i = n-1; i > n-1-k; i--)
            {
                mintk2 *= a[i].first;
            }
            ll ans = (1000000000+7)-mintk2.x;
            ans %= 1000000000+7;
            cout << ans << endl;
            return 0;
        }
    }

    if (hugo%2 != 0){
        ll mtop, ptom;

        if (maxm == 1e10) maxm = -1;
        if (maxp == 1e10) maxp = -1;
        if (minp == 1e10){
            //k個のうち全てマイナス
            ptom = -1;
            mtop = 0;
        } else {
            ptom = minm * maxm;
            mtop = minp * maxp;
        }

        if (ptom > mtop){
            mintk *= maxm;
            mintk /= minp;
        } else {
            mintk *= maxp;
            mintk /= minm;
        }
    }    

    cout << mintk.x << endl;
}

