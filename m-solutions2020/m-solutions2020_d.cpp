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
    vector<int> a(n);
    rep(i, n){ cin >> a[i]; }

    vector<ll> updown;
    updown.push_back(a[0]);
    int up = a[1] - a[0];
    up = (up != 0) ? up/abs(up) : 0; 
    up = 0;
    for (int i = 1; i < n; i++)
    {
        int tup = a[i] - a[i-1];
        tup = (tup != 0) ? tup/abs(tup) : 0; 
        if (up != 0){
            if (up != tup && tup != 0){
                //hanten
                updown.push_back(a[i-1]);
                up = tup;
            }
        } else {
            up = tup;
        }
    }
    if (updown[updown.size()-1] != a[n-1] ) updown.push_back(a[n-1]);

    //show(updown);

    if (updown.size() == 1) {
        cout << "1000" << endl;
        return 0;
    }

    bool upst = true;
    if (updown[0] > updown[1]){
        upst = false;
    }
    ll ans = 1000;
    ll kabu = 0;
    rep(i, updown.size()/2){
        if (upst){
            if (i*2+1 >= updown.size()) break;
            kabu = ans/updown[i*2];
            ans -= kabu*updown[i*2];
            ans += kabu*updown[i*2+1];
        } else {
            if (i*2+2 >= updown.size()) break;
            kabu = ans/updown[i*2+1];
            ans -= kabu*updown[i*2+1];
            ans += kabu*updown[i*2+2];
        }     
    }

    cout << ans << endl;
}

