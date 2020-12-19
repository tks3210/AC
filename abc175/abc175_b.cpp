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
    vector<ll> a(n);
    rep(i, n){ cin >> a[i]; }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if (a[i] == a[j]) continue;
                if (a[j] == a[k]) continue;
                if (a[k] == a[i]) continue;
                
                if (a[i] + a[j] <= a[k]) continue;
                if (a[j] + a[k] <= a[i]) continue;
                if (a[k] + a[i] <= a[j]) continue;
                //cout << i << j << k << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    
}

