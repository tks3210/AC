#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;


int main()
{
    int n, k, r, s, p;
    cin >> n >> k >> r >> s >> p;
    string t;
    cin >> t;
    
    vector<int> t_div[k];
    int hand[3] = {p, r, s};

    rep(i, n){
        if (t[i] == 'r'){
            t[i] = 0;
        } else if(t[i] == 's'){
            t[i] = 1;
        } else {
            t[i] = 2;
        }
        t_div[i%k].push_back(t[i]);
    }

    ll ans = 0;
    rep(i, k){
        int old = -1;
        rep(j, t_div[i].size()){
            if (t_div[i][j] != old){
                ans += hand[t_div[i][j]];
                old = t_div[i][j];
            } else {
                old = -1;
            }
        }
        //cout << ans << endl;
    }

    cout << ans << endl;
}

