#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
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

int main()
{
    int x = 2000000000;
    struct mint m(x);
    //和(2000000000 + 3000000000)
    cout << "+:   " << (m + 3000000000).x << endl; 
    //差(2000000000 - 1000000000)
    cout << "-:   " << (m - 1000000000).x << endl; 
    //積(2000000000 * 20)
    cout << "*:   " << (m * 20).x << endl; 
    //商(2000000000 / 20)
    cout << "/:   " << (m / 20).x << endl; 
    //累乗(2000000000^2000000000)
    cout << "a^b: " << (m.pow(2000000000)).x << endl;
    
    //Combination計算 n = 50000000000 m = 3
    ll N = 50000000000;
    ll M = 3;
    mint fac(1), ifac(1);
    for (int i = 0; i < M; i++){ fac *= N - i; } //nCmの分子を計算
    for (int i = 0; i < M; i++){ ifac *= i + 1; } //nCmの分母を計算
    ll ans = (fac * ifac.inv()).x; //分子に分母の逆元を積算
    cout << "nCm: " << ans << endl;


}