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

int main(){
    int n;
    vector<ll> a;
    cin >> n;
    rep(i, n){
        int t; cin >> t; a.push_back(t);
    }

    mint csum(0);
    mint mut(1);
    rep(i, n){
        csum += (mint)1 / (mint)(i+1);
        mut *= i + 1;
    }

    mint ans(0);
    rep(i, n){
        mint part(0);
        if (i != 0){
            csum += (mint)1 / (mint)(i + 1);
            csum -= (mint)1 / (mint)(n - (i - 1));
        }
        part = csum * a[i];
        part *= mut;
        //cout << i << " "<< csum.x << " "<< part.x << endl;
        ans += part;
    }
    //ans *= mut;

    cout << ans.x << endl;
}