#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<vector<int> > dp(3);
    vector<vector<int> > act(3); 
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        act[0].push_back(a); 
        act[1].push_back(b); 
        act[2].push_back(c); 
    }
    
    dp[0].push_back(act[0][0]);
    dp[1].push_back(act[1][0]);
    dp[2].push_back(act[2][0]);
        
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int maxval = max(dp[(j+1)%3][i], dp[(j+2)%3][i]);
            dp[j].push_back(maxval + act[j][i]);
            printf("%d %d %d\n",i, j, dp[j][i]);            
        }
    }
    int ans = 0;
    ans = max(max(dp[0][n - 1], dp[1][n - 1]), dp[2][n - 1]);

    cout << ans << endl;

}
