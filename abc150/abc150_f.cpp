#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
typedef long long ll;

// Morris-Pratt
// https://youtu.be/9MphwmIsO7Q?t=7283
template<typename T>
struct MP {
  int n;
  T t;
  vector<int> a;
  MP() {}
  MP(const T& t): t(t) {
    n = t.size();
    a = vector<int>(n+1);
    a[0] = -1;
    int j = -1;
    for (int i = 0; i < n; ++i) {
      while (j != -1 && t[j] != t[i]) j = a[j];
      j++;
      a[i+1] = j;
    }
  }
  int operator[](int i) { return a[i];}
  vector<int> findAll(const T& s) {
    vector<int> res;
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
      while (j != -1 && t[j] != s[i]) j = a[j];
      j++;
      if (j == n) {
        res.push_back(i-j+1);
        j = a[j];
      }
    }
    return res;
  }
};


vector<int> f(vector<int>& in){
    vector<int> out;
    int n = in.size();
    for (int i = 0; i < n; i++) out.push_back(in[i]^in[(i+1)%n]);
    return out;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<int> wa = f(a);
    vector<int> wb = f(b);
    wb.insert(wb.end(), wb.begin(), wb.end());
//    show(wa);
//    show(wb);
    struct MP<vector<int>> mp(wa);
    vector<int> res = mp.findAll(wb);
//    show(res);
    vector<int> k;
    rep(i, res.size()) k.push_back(n-res[i]);
    sort(k.begin(), k.end());
    rep(i, k.size()){
        if (k[i] == n) continue;
        int ans = a[k[i]]^b[0];
        cout << k[i] << " " << ans << endl;
    }

    return 0;
}

