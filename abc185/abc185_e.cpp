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
        return bit[i]^sum(i-(i&-i));
    }
    void add(int i, int x) {
        if (i == 0) return;
        if (i > M) return;
        bit[i] = bit[i]^x;
        add(i+(i&-i), x);
    }
    int sum(int st, int end) {
        // [st, end)
        if (st == 0) st = 1;
        return sum(end-1)^sum(st-1);
    }
    int get(int i){
        if (i <= 0 || i > M) return 0;
        return sum(i, i+1);
    }
};

const int n_max = 31;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i, n){ cin >> a[i]; }

    vector<vector<int>>  keta(n_max, vector<int>(n));

    rep(i, n){
        rep(ki, n_max){
            ll b = (ll)1 << ki;
            if ((a[i]&b) != 0) keta[ki][i] = 1;
            else keta[ki][i] = 0;
        }
    }

    //rep(ki, n_max) show(keta[ki]);

    vector<BIT> barray;
    rep(ki, n_max) {
        BIT tmp(n);
        rep1(i, n) {
            tmp.add(i, keta[ki][i-1]);
        }
        barray.push_back(tmp);
    }
    // rep1(i, n){
    //     cout << barray[0].sum(i) << endl;
    // }

    rep(qi, q){
        int t;
        
        ll x, y;
        cin >> t >> x >> y;
        if (t == 1){
            rep(ki, n_max){
                if (((y>>ki)&1) != 0) {
                    barray[ki].add(x, 1);
                }
            }
        } else {
            ll ans = 0;
            rep(ki, n_max){
                ll t = (ll)barray[ki].sum(x, y+1);
                ans += t<<ki;
            }
            cout << ans << endl;
        }
    }


}

