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

int main()
{
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    rep(i, n){ cin >> a[i]; }

    vector<ll> Asum;
    ll n1 = n/2;
    ll n2 = n - n/2;
    for (ll bit = 0; bit < (1 << n1); bit++) {
        ll sum = 0;
        for (ll i = 0; i < n1; i++) {
            ll mask = 1 << i;
            if (bit & mask) {
                sum += a[i];
            }
        }
        Asum.push_back(sum);
    }
    // グループ2をビット全探索で全列挙 (後半の半分)
    vector<ll> Bsum;
    for (ll bit = 0; bit < (1 << n2); bit++) {
        ll sum = 0;
        for (ll i = 0; i < n2; i++) {
            ll mask = 1 << i;
            if (bit & mask) {
                sum += a[n1 + i];
            }
        }
        Bsum.push_back(sum);
    }
    sort(Asum.begin(), Asum.end(), greater<ll>());  // A をソート

    sort(Bsum.begin(), Bsum.end(), greater<ll>());  // B をソート

    //show(Asum);
    //show(Bsum);

    ll ans = 0;
    rep(i, Asum.size()){
        ll remain = t - Asum[i];
        if (remain < 0) continue;
        int itr = lower_bound(Bsum.begin(), Bsum.end(), remain, greater<ll>()) - Bsum.begin();
        ll tans = Asum[i] + Bsum[itr];
        //cout << Asum[i] <<":" << remain << ":"<< tans << endl;
        chmax(ans, tans);
    }

    cout << ans << endl;
}

