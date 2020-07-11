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
素因数分解して
 2 2 2 2
 3 3 3
 4 4

各素因数の数

*/

void divsoinsu(map<ll, int>& divmap, ll input){
    for (ll i = 2; i*i <= input; i++)
    {
        while((input%i) == 0){
            if (divmap.find(i) == divmap.end()){
                divmap.insert({i, 1});
            } else {
                divmap[i]++;
            }
            input /= i;
        }
    }
    if (input != 1){
        if (divmap.find(input) == divmap.end()){
            divmap.insert({input, 1});
        } else {
            divmap[input]++;
        }
    }
}

int main()
{
    ll n;
    cin >> n;

    map<ll, int> dmap;
    divsoinsu(dmap, n);

    int ans = 0;
    for(auto x = dmap.begin(); x != dmap.end(); x++){
        //cout << x->first  << "  "<< x->second;
        int num = x->second;
        int tans = 1;
        while(1){
            num-=tans;
            if (num < 0){
                tans--; break;
            }
            tans++;
        }
        ans += tans;
    }

    cout << ans << endl;
}

