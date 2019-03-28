#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1000000000

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    vector<int> dp(n, INF);

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        //h.push_back(tmp); push_backは末尾に追加
        h[i] = tmp;
    }

    dp[0] = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j <= k && (i + j) < n; j++)
        {
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
            //printf("%d %d %d\n", i,j,dp[i + j]);
        }
    }
    
    cout << dp[n - 1] << endl;

}

