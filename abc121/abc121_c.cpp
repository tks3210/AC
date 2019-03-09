#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
 
int main(){
    int n, m;
    cin >> n >> m;
 
    vector<pair<ll, ll>> a;
    for(int i = 0; i < n; i++)
    {
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        a.push_back(make_pair(tmp1, tmp2));        
    }
 
    sort(a.begin(), a.end());
 
    ll totalcnt = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        if (m <= totalcnt + a[i].second){
            ans += (m - totalcnt)*a[i].first;
            break;
        } else {
            ans += a[i].second*a[i].first;
            totalcnt += a[i].second;
        }
        //printf("%d %d en %d  num %d\n", i, ans, a[i].first, a[i].second);
    }
    
    cout << ans << endl;
 
}