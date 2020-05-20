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


int main()
{
    int n, m;
    cin >> n >> m;

    vector<P> bat(m);


    int itr_f = 1;
    int itr_l = n;
    int sw = 0;
    rep(i, m){
        bat[i].first = itr_f;
        bat[i].second = itr_l-sw;
        itr_f++;
        itr_l--;
        if(itr_l-itr_f <= n/2 && n%2 == 0){
            sw = 1;
        }
    }

    rep(i, m){
        cout << bat[i].first << " " << bat[i].second << endl;
    }


}

