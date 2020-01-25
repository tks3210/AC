#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(y) for(auto i: y){cout << i.x << " ";}
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

//mint gcd(mint x, mint y){ return y.x?gcd(y, x.x%y.x):x;}
//mint lcm(mint x, mint y){ return (x*y)/gcd(x,y);}
ll gcd(ll x, ll y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

/*
* 最小公倍数の管理を数字で素因数で行う
* map<int, int>で素数、指数を管理する O(NrootN)
    * mapにおける値の更新
* 最小公倍数/数の計算
    * map<int, int>から指数を引いた数をmint掛け算する
* mint総和を取る

*/

map<int, int> minlcm;

void factorization(int input, map<int, int> &mp){

    for (int i = 2; i*i <= input; i++)
    {
        if (input % i == 0){
            while (input % i == 0){
                input /= i;
                if (mp.find(i) == mp.end()){
                    mp.insert(make_pair(i, 1));            
                } else {
                    mp[i]++;
                }
            }
        }
    }
    if (input != 1) mp.insert(make_pair(input, 1));
    // for (auto itr = mp.begin(); itr != mp.end(); itr++)
    // {
    //     cout << "key = " << itr->first << ", val = " << itr->second << "\n";
    // }
}

mint calclcm(vector<int>& a){
    rep(i, a.size()){
        map<int, int> mp;
        factorization(a[i], mp);
        for (auto itr : mp){
            if(minlcm.find(itr.first) == minlcm.end()){
                minlcm.emplace(itr.first, itr.second);
            } else {
                minlcm[itr.first] = max(minlcm[itr.first], itr.second);                
            }
        }
    }

    mint ans(1);
    for (auto itr : minlcm)
    {
        mint k = itr.first;
        ans *= k.pow(itr.second);
        //cout << "key = " << itr.first << ", val = " << itr.second << "\n";
    }
    //cout << ans.x << endl;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}
    
    mint mlcm = calclcm(a);
    mint ans(0);
    rep(i, n){
        ans += mlcm /(mint)a[i];
    }

    cout << ans.x << endl;
}


