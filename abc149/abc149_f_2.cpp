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

typedef struct{
    int st;
    int des;
    int child;
} lineInfo;

vector<lineInfo> lineinfo;

int dfs(int parent, int node, vector<vector<int>>& line){
    if (parent != -1  && line[node].size() == 1) {
        return 1;
    }
    int childsum = 0;
    int childmax = 0;
    for(auto next: line[node]){
        if (next == parent) continue;
        int score = dfs(node, next, line);
        childsum += score;
        childmax = max(childmax, score);
        lineinfo.push_back({node+1, next+1, score});
    }

    return childsum + 1;
}


mint calprob(int e, int n){
    mint m1(2), m2(2), m3(2);
    return (m1.pow(e) - (mint)1) * (m1.pow(n-e) - (mint)1);  
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> line(n);
    rep(i, n-1){
        int tmpa, tmpb;
        cin >> tmpa >> tmpb;
        tmpa--; tmpb--;
        line[tmpa].push_back(tmpb);
        line[tmpb].push_back(tmpa);    
    }

    dfs(-1, 0, line);

    mint ans(0);
    for(auto l: lineinfo){
        //cout << l.st << ":" << l.des << ":" << l.child << endl;
        ans += calprob(l.child, n);       
    }
    ans -= 1;
    mint m(2);
    ans += m.pow(n);
    ans -= m.pow(n) * n / 2;
    ans /= m.pow(n);
    cout << ans.x << endl;
}

