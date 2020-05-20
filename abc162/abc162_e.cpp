#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << i.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
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

template<class X> void factorization(X input, vector<X>& Pnumber){
    for(X i = 2; i*i <= input; i++)
    {
        if (input % i == 0){
            while (input % i == 0){
                input /= i;
                Pnumber.push_back(i);
            }
        }
    }
    if (input != 1) Pnumber.push_back(input);
}

/*
1~K以下の整数からなる長さNの数列
この数列は、K^Nのパターンが存在する。

この数列のK^Nの最大公約数の和
最大公約数がXとなるときのパターン数をf(X)とする。
f(K) = 1 (全てK)
f(K/2) = 2^N - f(K) 

pをmの公倍数かつK以下の数とする。
f(m): (pの数)^N -  f(p)の総和

 */

int main()
{
    int n, k;
    cin >> n >> k;

    vector<mint> f(k+1, 0);
    for (int m = k; m >= 1; m--)
    {
        //f(m)を包除原理で求める。
        int pnum = k/m;
        mint tans = pnum;
        tans = tans.pow(n);
        for (int i = 2; i <= pnum; i++)
        {
            tans -= f[m*i];
        }
        f[m] = tans;
    }
    
    mint ans(0);
    for (int i = 1; i <= k; i++)
    {
        //cout << f[i].x << endl;
        mint tans = f[i];
        tans *= i;
        ans += tans;
    }
    
    cout << ans.x << endl;
}

