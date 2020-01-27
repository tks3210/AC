#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000000
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;

int dp[1050][10050] = {0};

int main()
{
    int h, n;
    cin >> h >> n;
    vector<P> a;
    rep(i, n){ int tmp1, tmp2; cin >> tmp1 >> tmp2; a.push_back(P(tmp1, tmp2));}

    rep(i, n+1)rep(j, h+1){
        dp[i][j] = INF;
    }

    dp[0][0] = 0;
    rep(i, n)rep(j, h+1){
        if(j == 0){
            dp[i+1][j] = 0;
        } else {
            dp[i+1][j] = min(dp[i][j], dp[i+1][max(0, j-a[i].first)] + a[i].second); 
        }
    }

    cout << dp[n][h] << endl; 
}

