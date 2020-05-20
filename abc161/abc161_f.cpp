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


/*
約数

正の整数N(2<=N<=10^12)と2以上N以下のKに対して、
NがK未満になるまで次の操作を繰り返す。

N%K=0のときNをKで割る、そうではないとき、NからKを引く

最終的にN=1となるようなKの決め方の総数は？

N: K => 1
N: 1+K => 1

N: 1+mK => 1
(1) N-1の公約数を列挙する
    ⇒総和が答え
(2) Nの公約数を列挙する（N-1の公約数と重複しない）
    ⇒一つづつ確かめる。公約数の最小値は2のため、2^30 = 10^12より、計算量はそこまでかからん。

コーナーケースにご用心
*/



template<class X> void divisor(X input, vector<X>& Dnumber){
    for (X i = 2; i*i <= input; i++)
    {
        if (input % i == 0){
            Dnumber.push_back(i);
            if (i * i  != input) Dnumber.push_back(input / i);
        }
    }
    Dnumber.push_back(input);
    sort(Dnumber.begin(), Dnumber.end());
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> div;
    vector<ll> divm;

    divisor(n, div);
    divisor(n-1, divm);

    int ans = divm.size();
    //show(div);
    rep(i, div.size()){
        ll tn = n;
        while(1){
            if (tn%div[i] == 0){
                tn /= div[i];
            } else {
                if (tn == tn%div[i]) break;
                tn %= div[i];
            }
            if (tn==1){
                ans++;
                break;
            }

        }
    }
    if (n==2) ans = 1;
    cout << ans << endl;
}

