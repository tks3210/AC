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

template<class X> void divisor(X input, vector<X>& Dnumber){
    for (X i = 1; i*i <= input; i++)
    {
        if (input % i == 0){
            Dnumber.push_back(i);
            if (i * i  != input) Dnumber.push_back(input / i);
        }
    }
    sort(Dnumber.begin(), Dnumber.end());
}

int main()
{
    ll s, p;
    cin >> s >> p;

    vector<ll> div;
    divisor(p, div);

    //show(div);
    rep(i, div.size()){
        ll a = div[i];
        ll b = p/a;
        if (a+b==s){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

}

