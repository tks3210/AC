#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


/*
dp 数列選択

長さNの整数列(N <= 2*10^5)の内N/2(切り捨て)の要素を、どの要素も隣接しないように選んだ時の最大和

Nが偶数のときは二パターンのみ。

Nが奇数のときは、以下のように考える。

A1から見たとき、選択権を持ちながら二回スキップできる。
一回もスキップしていない場合、一意に定まるA1, A3, A5, ...
ある地点でスキップした場合、A_x(xは偶数),A_x+2, A_x+4, A_x+6
二回スキップした場合、A_N, A_N-2, A_N-4, ...

一回目のスキップから二回目のスキップの区間の最適値を求めれば解ける？

解の二分探索？
　ある値Xを超えることができる場合が存在するか否かをO(N)で算出できれば解ける？

skipの位置で考えようとしても、パターンが掴みにくそう
dp[i][skip_num][selected]: 
　i番目の時点で、skip_num回skipをした際の、最大数(selected=1のとき、i番目の数字を選択)

dp[i+1][skip_num][0] = max(dp[i][skip_num][1], dp[i][skip_num-1][0]) 
dp[i+1][skip_num][1] = dp[i][skip_num-1][0] + a[i]

0 <= skip_num <= 2

dp[n][1/2][0/1]のうち最大値が答え

oxoxoxs
oxoxsox
oxoxsso
oxsoxox
oxsoxso
oxssoxo
soxoxox
soxoxso
soxsoxo
ssoxoxo

自力AC　1時間強かかった

*/

#define INF 10e15

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<ll>> dp(3, vector<ll>(2, -INF));
    //dp[i][j]: i:skip回数、j=1の時a[i]を選択している状態における最大値
    dp[0][1] = a[0];
    dp[1][0] = 0;
    for (int s = 1; s < n; s++)
    {
        vector<vector<ll>> tdp(3, vector<ll>(2, -INF));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                tdp[i][0] = dp[i][1];
                tdp[i][1] = dp[i][0] + a[s];
                if (i!=0){
                    tdp[i][0] = max(dp[i-1][0], tdp[i][0]);
                }
               // printf("%d, %d, %lld\n", i,j, tdp[i][j]);
            }
        }
        dp = tdp;
    }

    ll ans = -INF;
    if (n%2 == 0){
        ans = max(dp[1][1], dp[0][0]);
        cout << ans << endl;
        return 0;
    }

    for (int i = 1; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
}
