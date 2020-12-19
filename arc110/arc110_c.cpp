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

class BIT
{
public:
    vector<int> bit;
    int M;

    BIT(int M):
        bit(vector<int>(M+1, 0)), M(M) {}

    int sum(int i) {
        if (!i) return 0;
        return bit[i] + sum(i-(i&-i));
    }

    void add(int i, int x) {
        if (i > M) return;
        bit[i] += x;
        add(i+(i&-i), x);
    }
};


//転倒数をbitで求める、
//番号が
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){ cin >> a[i]; }

    bool ok = true;
    BIT bit(n);
    int tmp = 0;
    vector<int> ans;
    rep(i, n){
        bit.add(a[i], 1);
        int x = i+1 - bit.sum(a[i]);
        //cout << x << endl;
        if (x != 0){
            if ((tmp + x) != i) ok = false;
            ans.push_back(x);
            tmp += x;
        }
    }
    if (!ok || tmp != n-1) {cout << -1 << endl; return 0;}

    int tmp2 = 0;
    rep(i, ans.size()){
        rep(j, ans[i]){
            cout << tmp2 + ans[i] - j << endl;
        }
        tmp2 += ans[i];
    }
}

