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
    int n;
    cin >> n;

    ll p = 1;
    ll m = -1;

    vector<ll> th;

    ll bai = 1;
    vector<ll> m2;

    const int max_bit = 35;
    rep(i, max_bit){
        m2.push_back(bai);
        if (i%2 == 0){
            th.push_back(p);
            p += bai;
        } else {
            th.push_back(m);
            m += bai;
        }
        bai *= -2;
    }

  //  show(th);

    ll nn = n;
    vector<int> bit(max_bit, 0);
    for (int i = max_bit - 1; i >= 0; i--)
    {
        if (i%2 == 0){
            if (th[i] <= nn) {nn -= m2[i]; bit[i] = 1;}
        } else {
            if (th[i] >= nn) {nn -= m2[i]; bit[i] = 1;}
        }
    }
    
    //show(bit);

    bool iswrite = false;
    for (int i = max_bit - 1; i >= 0; i--)
    {
        if (bit[i] == 1){
            iswrite = true;
        }
        if (iswrite) cout << bit[i];
    }
    
    if (!iswrite) {cout << 0 << endl; return 0;}
    cout << endl;
    
}

