#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    vector<ll> a, b;
    rep(i, n + 1){ ll tmp; cin >> tmp; a.push_back(tmp);}
    rep(i, n){ ll tmp; cin >> tmp; b.push_back(tmp);}

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] >= a[i]){
            ans += a[i];
            b[i] -= a[i];
            a[i] = 0;
            if (b[i] >= a[i + 1]){
                ans += a[i + 1];
                b[i] -= a[i + 1];
                a[i + 1] = 0;
            } else {
                ans += b[i];
                a[i + 1] -=  b[i];
            }
        } else {
            ans += b[i];
            a[i] -= b[i];
        }
    }
    cout << ans << endl; 
}

