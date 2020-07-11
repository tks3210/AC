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
    ll n;
    cin >> n;

    vector<ll> num;
    ll name = n;

    vector<ll> min26_len;
    min26_len.push_back(1);
    ll min26 = 26;
    ll len = 1;
    while(1){
        name -= min26;
        min26_len.push_back(min26);
        if (name <= 0) break;
        min26 *= 26;
        len++;
    }
    //cout << len << endl;

    min26 = 1;
    name = n;
    for (int i = 0; i < len; i++)
    {
        name -= min26;
        min26 *= 26;
    }
    
    //cout << name << endl;
    for (int i = len; i > 0; i--)
    {
        char tans = name/min26_len[i-1];
        name %= min26_len[i-1];
        char c = tans + 'a';
        cout << c ; 
    }
    cout << endl;


}

