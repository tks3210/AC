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

int mod = 3;
typedef struct mint
{
    ll x;
    mint(ll x = 0) : x(x % mod){} //コンストラクタ
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

int main()
{
    int n, p;
    cin >> n >> p;
    vector<int> amaribox(p, 0); //modの数を管理
    string s;
    cin >> s;
    mod = p;

    ll ans = 0;
    if (p != 2 && p != 5){
        mint kurikoshi(0);
        mint keta_mod(1);
        rep(i, n){
            int num = (s[n-1-i] - '0') % p;

            kurikoshi += keta_mod * num ;
            keta_mod *= 10;
 //           cout << kurikoshi.x << ":" << num << ":" << keta_mod.x<< endl;

            if (kurikoshi.x == 0) ans++;
            ans += amaribox[kurikoshi.x];

            amaribox[kurikoshi.x] += 1;
        }

    } else {
        // rep(i, n){
        //     int num = (s[n-1-i] - '0') % p;
        //     if (num == 0) ans += n-i;
        // }
    }

    cout << ans << endl;

}


/*
aがある数xで割り切れる
0 (mod x)
a = b - c としたとき、b = c (mod x)

xx0000が10に対して互いに素である数pで割り切れるとき、
xxもある数pで割り切れる
*/