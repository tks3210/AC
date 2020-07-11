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
/*
範囲が制限されたn個の数字の列が取り得る中央値の数
nが偶数の時、中央二つの数の平均が中央値となる。

中央値に絡む数
ある数が中央値になり得るか？の判定

bの数列を二分探索して

非連結になることはなさそう。
偶数の場合二倍したうえで、最大値－最小値＋1をすれば良さそう



*/

int main()
{
    int n;
    cin >> n;
    vector<ll> a;
    vector<ll> b;
    rep(i, n){ 
        ll ta, tb;
        cin >> ta >> tb; 
        if ((n%2)==0){
            ta*=2, tb*=2;
        }
        a.push_back(ta);
        b.push_back(tb);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll amin, bmin;
    if (n%2 == 0){
        amin = a[(n/2)] + a[(n/2)-1];
        bmin = b[(n/2)] + b[(n/2)-1];
        amin /= 2;
        bmin /= 2;    
    } else {
        amin = a[n/2];
        bmin = b[n/2];
    }
    cout << bmin - amin + 1 << endl;

}

