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

int n;

int dfs(int parent, int node, vector<vector<int>>& line, vector<vector<int>>& v){
    int childsum = 0;

    if (parent != -1  && line[node].size() == 1) {
        v[node].push_back(n - childsum - 1);
        return 1;
    }
    for(auto next: line[node]){
        if (next == parent) continue;
        int score = dfs(node, next, line, v);
        childsum += score;
        v[node].push_back(score);
    }
    v[node].push_back(n - childsum - 1);
    return childsum + 1;
}


mint calprob(int e, int n){
    mint m1(2), m2(2), m3(2);
    return (m1.pow(e) - (mint)1) * (m1.pow(n-e) - (mint)1);  
}

int main()
{
    cin >> n;
    vector<vector<int>> line(n);
    rep(i, n-1){
        int tmpa, tmpb;
        cin >> tmpa >> tmpb;
        tmpa--; tmpb--;
        line[tmpa].push_back(tmpb);
        line[tmpb].push_back(tmpa);    
    }

    //各頂点の個数を格納
    vector<vector<int>> v(n);
    dfs(-1, 0, line, v);

    mint ans(0);
    mint two(2);
    rep(i, n){
      mint pat(0);
      pat += two.pow(n-1); //自分が白のパターン
      pat -= 1; //全て白のパターン
      for(auto e: v[i]){
        pat -= two.pow(e) - 1;
      }
      //cout << i << ":"<< pat.x << endl;
      ans += pat;
    }
    ans /= two.pow(n);
    cout << ans.x << endl;
}

