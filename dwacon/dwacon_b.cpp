#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

const int mod = 1000000007;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
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


int main()
{
    ll n;
    cin >> n;
    vector<ll> x;
    rep(i, n){ ll tmp; cin >> tmp; x.push_back(tmp);}

    vector<ll> sum;
    ll sum_cnt = 0;
    rep(i, n + 1) {
        sum.push_back(sum_cnt);
        sum_cnt += x[i];
    }

    mint ans_m(0); //答え
    mint mut(1); //(n-1)!除算
    for (ll i = 1; i < n; i++)
    {
        mint m(i);
        mut *= m;
    }
    mint sumprob(0);
    rep(i, n - 1){
        ll ip = i + 1;
        mint ans_part(0);
        mint line = x[ip] - x[i];
        sumprob += (mint)1/(mint)ip;
        ans_part = sumprob * line;
        ans_part *= mut;
        //cout << ans_part.x << endl;
        ans_m += ans_part;
    }

    cout << ans_m.x << endl;

}

