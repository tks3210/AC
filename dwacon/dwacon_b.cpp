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

    vector<mint> sum;
    mint sum_cnt = 0;
    rep(i, n + 1) {
        sum.push_back(sum_cnt);
        sum_cnt += x[i];
    }

    cout << endl;

    mint ans_m(0);
    mint mut(1);
    for (ll i = 1; i < n; i++)
    {
        mint m(i);
        mut *= m;
    }
    rep(i, n - 1){
        ll ip = i + 1;
        mint part_m(0);
        mint mutbuf(mut);

        for (int j = i + 1; j < n; j++)
        {
            mint m2(2);
            mint ppart_m(0);
            ppart_m += x[j] - x[i];
            cout << "::" << ppart_m.x << endl;
            ppart_m /= (j == n-1) ? m2.pow(n-(ip + 1)) : m2.pow(j - i);
            mint aa = (j == n-1) ? m2.pow(n-(ip + 1)) : m2.pow(j - i);
            cout << ":" << aa.x << endl;
            part_m += ppart_m;
        }
        part_m *= mut;
        cout << "num?:" <<part_m.x << endl;
        ans_m += part_m;
    }

    cout << ans_m.x << endl;

}

