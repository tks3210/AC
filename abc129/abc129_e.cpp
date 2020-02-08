#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;

long mod = 1000000007;
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

int main()
{
    string s;
    cin >> s;
    int len = s.size();
    mint ans;
    /*
    10101111001
    1***の計算 => もうちょい考えよ
    0***の計算 => 3^(len-1)
    */
    
    mint dp[100010][2] = {0};
    dp[0][0] = 1;//0,0になったことがある
    dp[0][1] = 2;//0,0になったことがない
    rep(i, len){
        if (i == 0) continue;
        if (s[i] == '1'){
            dp[i][0] = (dp[i-1][0] * 3) + (dp[i-1][1]);
            dp[i][1] = dp[i-1][1] * 2;
        } else {
            dp[i][0] = dp[i-1][0] * 3;
            dp[i][1] = dp[i-1][1];
        }
        //cout << i <<" " << dp[i][0].x <<" " << dp[i][1].x << endl;
    }

    cout << (dp[len-1][0] + dp[len-1][1]).x << endl;
}

