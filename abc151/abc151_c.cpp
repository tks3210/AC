#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;
typedef pair<int, string> P;

int main()
{
    int n, m;
    cin >> n >> m; 
    vector<P> a;
    rep(i, m){ int tmpp;  string tmps; cin >> tmpp >> tmps; tmpp--; a.emplace_back(tmpp, tmps);}

    vector<pair<bool, int>> ac_flag(n, make_pair(false, 0));

    rep(i, m){
        if (!ac_flag[a[i].first].first){
            if (a[i].second == "AC"){
                ac_flag[a[i].first].first = true;    
            } else {
                ac_flag[a[i].first].second++;    
            }
        }
        
    }

    int ac_cnt = 0;
    int wa_cnt = 0;
    for(auto ac : ac_flag){
        if (ac.first == true){
            ac_cnt++;
            wa_cnt+=ac.second;
        }
    }

    cout << ac_cnt <<  " "<< wa_cnt << endl;
}

