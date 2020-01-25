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

void comp(ll b, int n, vector<mint>& q){
    
    mint x(1);
    rep(i, n + 1){
        if (i < b) {
            q.push_back(0);
        } else if (i == b){
            q.push_back(1);
        } else {
            x *= (mint)i;
            x /= (mint)(i-b);
            q.push_back(x);
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}

    sort(a.begin(), a.end());

    vector<int> adiff;
    rep(i, n-1){ adiff.push_back(a[i+1] - a[i]);}
    vector<mint> comp_arr;
    comp(k, n, comp_arr);
    //for(auto i: comp_arr){cout << i.x << " ";}
    //cout << endl;
    mint ans = 0;
    rep(i, n-1){
        mint sub = comp_arr[n] - comp_arr[i+1] - comp_arr[n-(i+1)];
        //cout << sub.x << endl;
        ans += sub * (mint)adiff[i];
    }

    cout << ans.x << endl;

}

