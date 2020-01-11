#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

bool cmp(const pair<ll, bool> &a, const pair<ll, bool> &b){
    if (a.first != b.first){
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
}

int main()
{
    ll n, x, d;
    cin >> n >> x >> d;
    x = abs(x); d = abs(d);
    int minus = 1;
    if (x*d < 0) minus = -1;
    vector<vector<pair<ll, bool>>> range(d); 

    range[0].push_back(make_pair(0, true));
    range[0].push_back(make_pair(0, false));
    rep(i, n){
        int N = i+1;
        int plus = (N / d) * x * minus;
        range[N%d].push_back(make_pair(((N-1) * N / 2) + plus, true));
        range[N%d].push_back(make_pair(((n * N) - (N*(N + 1)/2)) + plus, false));
    }


    rep(i, d){
        sort(range[i].begin(), range[i].end(), cmp);
            // for (auto num: range[i])
            // {
            //     cout << num.first << " ";
            // }
            // cout << endl;
    }

    int ans = 0;
    rep(i, d){
        int cnt = 0;
        int bef = 0;
        for (auto num: range[i])
        {
            if (num.second == true){
                if (cnt == 0){
                    bef = num.first;
                }
                cnt++;
            } else {
                cnt--;
            }

            if(cnt == 0){
                ans += num.first - bef + 1;
            }
        }
        cout << ans << endl;

    }


}


