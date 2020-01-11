#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

int mapabs[81][81] = {0};
bool dp[81][81][160*160] = {0};
#define OFFSET 80*160

int main()
{
    int h, w;
    cin >> h >> w;
    rep(i, h)rep(j, w){
        int tmp; cin >> tmp;
        mapabs[i][j] = tmp; 
    }
    rep(i, h)rep(j, w){
        int tmp; cin >> tmp;
        mapabs[i][j] = abs(tmp - mapabs[i][j]); 
    }

    // rep(i, h){
    //     rep(j, w){
    //         cout << mapabs[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    dp[0][0][OFFSET+mapabs[0][0]] = true;
    dp[0][0][OFFSET-mapabs[0][0]] = true;
    rep(i, h){
        rep(j, w){
            rep(k, OFFSET*2){
                if (i != 0){
                    if ((dp[i - 1][j][max(k - mapabs[i][j], 0)] == true) || 
                    (dp[i - 1][j][min(k + mapabs[i][j], 160*160-1)] == true))
                    {
                        dp[i][j][k] = true;
                    }
                }
                if (j != 0){
                    if ((dp[i][j - 1][max(k - mapabs[i][j], 0)] == true) || 
                    (dp[i][j - 1][min(k + mapabs[i][j], 160*160-1)] == true))
                    {
                        dp[i][j][k] = true;
                    }
                }

            }
        }
    }
    int ans = 81;
    for(int i = -80; i <= 80; i++){
        if (dp[h-1][w-1][i+OFFSET] == true){
            ans = min(ans, abs(i));
        }
    }
    cout << ans << endl;
}

