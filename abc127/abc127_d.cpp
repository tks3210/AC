#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


bool cmp(const P &a, const P &b){
    return a.second > b.second;
} 

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}
    vector<P> bc;
    rep(i, m){ int tmpb, tmpc; cin >> tmpb >> tmpc; bc.push_back(P(tmpb, tmpc));}

    sort(a.begin(), a.end());

    sort(bc.begin(), bc.end(), cmp);

    vector<int> cmp;
    for (auto itr: bc)
    {
        rep(i, itr.first){
            cmp.push_back(itr.second);
        }
        if (cmp.size() >= n) break;    
    }

    ll ans = 0;    
    rep(i, n){
        if (i < cmp.size()){
            ans += max(a[i], cmp[i]);
        } else {
            ans += a[i];
        }
    }
    cout << ans << endl;
    
}

