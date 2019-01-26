//submisssions/4054148を参考

#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
 
 
int main()
{
    int n, k;
    cin >> n >> k;
    //二次元動的配列の使いかた
    vector<ll> a(n), b(n);
    vector<vector<ll>> v(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
        v[--a[i]].push_back(b[i]);
    }
    //for(auto& x : v){
    //    sort(x.begin(), x.end(), greater<ll>());
    //}
    for(int i = 0; i < n; i++)
    {
        sort(v[i].begin(),v[i].end(), greater<ll>());
    }
    

    vector<ll> top;
    vector<ll> notop;

    for(int i = 0; i < n; i++)
    {
        if(v[i].empty())
            continue;
        top.push_back(v[i][0]);
        for(int j = 1; j < v[i].size(); j++)
        {
            notop.push_back(v[i][j]);            
        }
    }
    
    sort(top.begin(), top.end(), greater<ll>());
    sort(notop.begin(), notop.end(), greater<ll>());

    ll ans = 0;
    for(ll i = 0; i <= k; i++)
    {
        if (i > top.size() || (k - i) > notop.size()) continue;

        ll tmp = 0;
        for(ll j = 0; j < k; j++)
        {

            if (j < i){
                tmp += top[j];
            }else{
                tmp += notop[j - i];
            }
        }
        //int iだとWAになった。iは10^5まで取りうるの注意
        tmp += i*i;
        ans = max(ans, tmp);  
    }
    cout << ans << endl;
}