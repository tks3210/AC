
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;


bool plus_comp(pair<ll, ll> one, pair<ll, ll> ano){
    return (one.first + one.second) > (ano.first + ano.second);
}

int main(){
    int n;
    vector<pair<ll, ll>> p;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        p.push_back(make_pair(tmp1, tmp2));
    }
    

    sort(p.begin(), p.end(), plus_comp);

    ll ans = 0;
    for(int i = 0; i < p.size(); i++)
    {
        if(i % 2 == 0){
            ans += p[i].first;
        }else{
            ans -= p[i].second;
        }
    }
    

    cout << ans << endl;

}