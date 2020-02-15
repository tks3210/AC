#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;



int main()
{
    string n;
    int K;
    cin >> n >> K;

    int len = n.size();

    // dp[j][k]: jは使用した非ゼロ, kは0の時=状態
    int dp[4][2] = {0};
    dp[0][0] = 1;
    rep(i, len){
        int nextdp[4][2] = {0};
        int num = n[i] - '0'; //上位i+1桁目の数字をチェック
        rep(j, K+1)rep(k, 2)rep(d, 10){
            int nj = j, nk = k; 
            if (d != 0) nj++;
            if (nj > K) continue;
            if (k == 0){
                if (d > num) continue;
                if (d < num) nk = 1;
            }            
            nextdp[nj][nk] += dp[j][k];
        }        
        memcpy(dp, nextdp, sizeof(nextdp));
    }
    cout << dp[K][0] + dp[K][1] << endl;
}

