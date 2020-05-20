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
A, B, Nが与えられる。
floor(Ax/B) - A * floor(x/B)の最大値を求める
x はN以下の数字

floor(Ax/B)について
(Ax)%B が小さいほど無駄が少ない

x%Bが小さいほど無駄が少ない
 

Ax/B-floor(Ax/B) = ((Ax)%B)/B ...1
Ax/B-A*floor(x/B) =  A(x%B)/B ...2

1を最小化しつつ、2を最大化
((Ax)%B) - A(x%B)の最小値を求めたい
答えは　x = B-1 + Bkになる。（Nの制限がなければ。。。）

x%B = m のとき、

(Am)%B - Am = (A%B)*(m%B) - Am = (A%B - A)m
mが取り得る最大値のときが答え

*/

int main()
{
    ll a, b, n;
    cin >> a >> b >> n;

    //x%bが最大となる時が答え
    ll x = 0;
    if (n < b-1){
        x = n;        
    } else {
        x = b-1;
    }

    cout << (a*x)/b - a*(x/b) << endl;
}

