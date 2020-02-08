#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;

//local変数のサイズ
int dp1[3010][3010] = {0};
int dp2[3010][3010] = {0};
int main()
{
    int n,t;
    cin >> n >> t;
    vector<P> ab;
    ab.push_back(P(0, 0)); //ラベル調整
    rep(i, n){ int tmp, tmp2; cin >> tmp >> tmp2; ab.push_back(P(tmp, tmp2));}

    //dp1 dp[i][j]: i番目の荷物までを用いて時間jまでに抑える
    sort(ab.begin(), ab.end());
    rep1(i, n)rep1(j, t){
        if (j >= ab[i].first){
            dp1[i][j] = max(dp1[i-1][j], dp1[i-1][j - ab[i].first] + ab[i].second);
        } else {
            dp1[i][j] = dp1[i-1][j];
        }
    }

    //dp2 dp[i][j]: i~N番目の荷物までを用いて時間jまでに抑える

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= t; j++)
        {
            if (j >= ab[i].first){
                dp2[i][j] = max(dp2[i+1][j], dp2[i+1][j - ab[i].first] + ab[i].second);
            } else {
                dp2[i][j] = dp2[i+1][j];
            }
        }
    }
    int ans = 0;
    rep1(i, n)rep1(j, t-1){
        //cout << dp1[i-1][j] << ":" << dp2[i+1][t-1-j] << ":" << ab[i].second << "::";
        //cout << dp1[i-1][j] + dp2[i+1][t-1-j] + ab[i].second << ":" << i <<":" <<j<<endl;
        ans = max(ans, dp1[i-1][j] + ab[i].second);
    }
    cout << ans << endl;
}

