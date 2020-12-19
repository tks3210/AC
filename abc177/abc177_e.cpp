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
setwise coprimeのはんてい　＝＞愚直にやる
pairwise coprimeのはんてい　＝＞　setで判定


*/

template<class X> void factorization(X input, set<X>& Pnumber){
    for(X i = 2; i*i <= input; i++)
    {
        if (input % i == 0){
            while (input % i == 0){
                input /= i;
                Pnumber.insert(i);
            }
        }
    }
    if (input != 1) Pnumber.insert(input);
}



int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n){ cin >> a[i]; }

    bool setc = false;
    ll s1 = a[0];
    for (int i = 1; i < n; i++)
    {
        s1 = gcd(s1, a[i]);
    }
    if (s1 == 1) setc = true;

    set<int> yakusu;
    bool pairc = true;
    rep(i, n){
        set<int> tmp;
        factorization(a[i], tmp);

        for (auto t: tmp){
            if (yakusu.find(t) == yakusu.end()){
                yakusu.insert(t);
            } else {
                pairc = false;
                break;
            }
        }
    }

    if (pairc) cout << "pairwise coprime" << endl;
    else if (setc) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
}

