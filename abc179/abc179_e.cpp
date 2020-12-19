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
    ll n, x, m;
    cin >> n >> x >> m;


    set<ll> numbox;
    vector<ll> numarray;

    ll f = x;
    ll tmp = x;
    int loopitr = -1;
    for(ll i=0; i<n; i++){
        if (numbox.find(tmp) != numbox.end()){
            rep(j, numarray.size()){
                if (numarray[j] == tmp) loopitr = j;
            }
            break;
        }
        numarray.push_back(tmp);
        numbox.insert(tmp);
        tmp *= tmp;
        tmp %= m;
    }

    if (x == 0) {cout << 0 << endl; return 0;}
    if (n == 1) {cout << x << endl; return 0;}
 //   show(numarray);


    ll ans = 0;
    vector<ll> sub_array;

    if (n <= numarray.size()){
        rep(i, n){
            ans += numarray[i];
        }
    } else {
        copy(numarray.begin() + loopitr, numarray.end(), back_inserter(sub_array));
       // show(sub_array);
        ll mainsum = 0;
        rep(i, numarray.size()) mainsum += numarray[i];
        ll subsum = 0;
        rep(i, sub_array.size()) subsum+= sub_array[i];

        ll remain = n-numarray.size();
        if (sub_array.size() == 0) return 0;
        ll remain_x = remain/sub_array.size();
        ll remain_y = remain%sub_array.size();

        ans += mainsum;
        ans += remain_x*subsum;
        rep(i, remain_y) ans+=sub_array[i];
    }
    cout << ans << endl;
}

