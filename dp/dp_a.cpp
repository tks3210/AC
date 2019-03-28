#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> dp(n);

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        //h.push_back(tmp); push_backは末尾に追加
        h[i] = tmp;
    }

    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 2] + abs(h[i] - h[i - 2]), dp[i - 1] + abs(h[i] - h[i - 1]));
    }
    
    cout << dp[n - 1] << endl;

}

