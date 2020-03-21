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


int main()
{
    string s, t;
    cin >> s >> t;

    vector<set<int>> alpha(26);

    rep(i, s.size()){
        int id = s[i] - 'a';
        alpha[id].insert(i);
    }


    ll ans = 0;
    int itr = -1;
    rep(i, t.size()){
        int id = t[i] - 'a';
        if (alpha[id].empty()) {cout << -1 << endl; return 0;}
        auto new_itr = alpha[id].upper_bound(itr);
        if (new_itr == alpha[id].end()){
            itr = -1;
            itr = *alpha[id].upper_bound(itr);
            ans += s.size();
        } else {
            itr = *new_itr;
        }
    }
    ans += itr+1;

    cout << ans << endl;
}

