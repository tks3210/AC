#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<priority_queue<int, vector<int>, greater<int>>, int> P;

#define K_MAX 100
P state[K_MAX][K_MAX];

int main()
{
    int n, k;
    cin >> n >> k; 
    vector<int> v;
    rep(i, n){ int tmp; cin >> tmp; v.push_back(tmp);}

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; i + j <= n; j++)
        {
            rep(ip, i) {
                state[i][j].first.push(v[ip]);
                state[i][j].second += v[ip];
            }   
            rep(jp, j) {
                state[i][j].first.push(v[n-1-jp]);
                state[i][j].second += v[n-1-jp];
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; i + j <= n; j++)
    //     {
    //         cout << i << ":"<<j << "::" <<state[i][j].second << endl;
    //     }
    // }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; i + j <= n; j++)
        {
            rep(p, k-(i+j)){
                if (state[i][j].first.empty()) break;
                if (state[i][j].first.top() < 0){
                    state[i][j].second -= state[i][j].first.top();
                    state[i][j].first.pop();
                } else {
                    break;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; i + j <= n; j++)
        {
            if (i + j > k) continue;
            ans = max(ans, state[i][j].second);
        }
    }

    cout << ans << endl;
}

