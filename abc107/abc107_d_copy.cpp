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

int main()
{
    ll n;
    cin >> n;
    vector<int> a;
    int max_a = 0;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);
        max_a = max(max_a, a[i]);
    }


    int l = 0;
    int r = 1e9 + 1;
    int geta = n+1;
    while(abs(l-r) > 1){
        int mid = (l+r)/2;
        vector<int> ap(n);
        rep(i, n) ap[i] = (a[i] >= mid) ? 1 : -1;
        vector<int> sap(n+1, 0);
        rep(i, n) sap[i+1] = sap[i] + ap[i];

        //sapの転倒数をもとめる
        BIT bit(2*n + 10);
        ll tans = 0;
        rep(i, n+1) {
            bit.add(sap[i] + geta, 1);
            tans += (i+1) - bit.sum(sap[i] + geta);
        }

        //-1, 1からなる数列の任意の範囲の和が0以上になる数xを求める
        if (tans <= n*(n+1)/2/2){
            //
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}

