#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    vector<int> p;
    rep(i, n){ int tmp; cin >> tmp; p.push_back(tmp);}

    int minn = MOD;
    int ans = 0;
    rep(i, n){
        if (minn >= p[i]){
            ans++;
            minn = p[i];
        }
    }

    cout << ans << endl;
}

