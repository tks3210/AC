#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m);
    rep(i, m){
        int k;
        cin >> k;
        rep(j, k){
            int tmps; cin >> tmps;
            tmps--;
            s[i].push_back(tmps);
        }
    }
    vector<int> p;
    rep(i, m){
        int tmpp; cin >> tmpp;
        p.push_back(tmpp);
    }

    int ans = 0;
    rep(i, 1<<n){
        bool ng = false;
        rep(j, m){
            int right = 0;
            for(auto sw: s[j]){
                if (i>>sw & 1) right += 1;
            }
            if (right % 2 != p[j]) ng = true;
        }
        if (!ng) ans++;
    }

    cout << ans << endl;
}

