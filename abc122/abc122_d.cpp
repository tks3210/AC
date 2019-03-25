#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000'000'007

//DPを行うときは、規定したい状態数＝次元数
//
int dp[101][4][4][4];
int main()
{
    int N;
    cin >> N;
    /* A:0 G:1 C:2 T:3*/
    dp[0][3][3][3] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int c3 = 0; c3 < 4; c3++) //三つ前の文字
        {
            for (int c2 = 0; c2 < 4; c2++) //二つ前の文字
            {
                for (int c1 = 0; c1 < 4; c1++) //一つ前の文字
                {
                    for (int k = 0; k < 4; k++)
                    {
                        if (c3 == 0 && c1 == 1 && k == 2)
                            continue;
                        if (c3 == 0 && c2 == 1 && k == 2)
                            continue;
                        if (c2 == 0 && c1 == 1 && k == 2)
                            continue;
                        if (c2 == 0 && c1 == 2 && k == 1)
                            continue;
                        if (c2 == 1 && c1 == 0 && k == 2)
                            continue;
                        dp[i][c2][c1][k] += dp[i - 1][c3][c2][c1];
                        dp[i][c2][c1][k] %= MOD;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int c3 = 0; c3 < 4; c3++) //三つ前の文字
    {
        for (int c2 = 0; c2 < 4; c2++) //二つ前の文字
        {
            for (int c1 = 0; c1 < 4; c1++) //一つ前の文字
            {
                ans += dp[N][c3][c2][c1];
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;
}