#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    int n;
    cin >> n;
    vector<int> h;
    rep(i, n){ int tmp; cin >> tmp; h.push_back(tmp);}

    int ans = 0;
    int cnt = 0;
    rep(i, n-1){
        if (h[i] >= h[i+1]){
            cnt++;
        } else {
            cnt=0;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}

