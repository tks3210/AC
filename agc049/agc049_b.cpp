#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}

int main()
{
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    set<int> s_set;
    set<int> t_set;

    rep(i, s.size()) if (s[i] == '1') s_set.insert(i);
    rep(i, t.size()) if (t[i] == '1') t_set.insert(i);

    int ans = 0;
    int s_itr = -1;
    int t_itr = -1;
    rep(i, s.size()){
        bool son = (s_set.find(i) != s_set.end());
        bool ton = (t_set.find(i) != t_set.end());
        if(ton) {
            t_itr = i;
        }
        if(son){
            if (s_itr != -1){
                ans += i-s_itr;
                s_itr = -1;
            } else if (t_itr != -1){
                ans += i-*t_set.begin();
                t_set.erase(t_set.begin());
                t_itr = -1;
            } else {
                s_itr = i;
            }

        }
    }
    if (!t_set.empty()) cout << -1 << endl;
    else cout << ans << endl;

}

