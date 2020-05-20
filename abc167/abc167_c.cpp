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
    int n, m, x;
    cin >> n >> m >> x;

    vector<ll> c(n);
    vector<vector<ll>> a(n, vector<ll>(m, 0));

    rep(i, n) {
        cin >> c[i];
        rep(j, m){
            cin >> a[i][j];
        }
    }



    int ans = MOD;
    rep(i, 1<<n){
        int tans = 0;
        vector<int> rikaido(m, 0);
        bool isok = true;
        for (int b = 0; b < n; b++)
        {
            if ((i>>b)&1){
                //b番目の本を洗濯
                tans += c[b];
                rep(algo, m){
                    rikaido[algo] += a[b][algo];
                }
            }
        }
            rep(algo, m){
                //cout << rikaido[algo] << ":";
                if (rikaido[algo] < x){
                    isok = false;
                }
            }
        
        //cout << i << ":::" << tans << ";;;" << isok << endl;
        
        if (isok) ans = min(tans, ans);
    }

    if (ans == MOD) cout << -1 << endl;
    else cout << ans << endl;

}

