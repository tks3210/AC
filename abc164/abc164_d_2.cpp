#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define repr(i, a, b) for(int i = (int)(a); i <= (int)(b); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

/*
2019で割り切れる連続部分列の総和を求める。

公約数　部分列列挙　逆元

ここで2019は5でも2でも割り切れないため、
ある数X*10^nが2019で割り切れる場合、ある数Xも10で割り切れる。
これを加味すると、
下位の桁からm番目までの数字を使った部分列の2019で割った余りをm=1から求めていき、
同じ余りを持つm'(<m)が存在するとき、m'からmまでの部分列は2019で割り切れる。
よって、m'の数だけ足していけば全ての部分列が求まる。

2020のような10で割り切れる数を議論する場合はもう一癖あるらしい。
*/
int main()
{
    string s;
    cin >> s;

    ll ans = 0;
    int div = 0;
    vector<int> sdiv(s.size(), 0);
    sdiv[0] = 1;
    repr(i, 1, s.size()-1){
        sdiv[i] = sdiv[i-1]*10;
        sdiv[i] %= 2019;
    }

    map<int, int> nump;
    nump.insert({0,1});
    rep(i, s.size()){
        int c = s[s.size()-1-i] - '0';
        div += c*sdiv[i];
        div %= 2019;
        //cout << i <<":" << div << ":" << c << endl;
        if (nump.find(div) == nump.end()){
            nump.insert({div, 1});
        } else {
            ans += nump[div];
            nump[div]++;
        }
    }

    cout << ans << endl;

}

