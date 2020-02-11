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
    int k;
    cin >> n >> k;

    int len = n.size();

    // dp[k][l]: kは残り非0, lは1の時=状態
    int dp[4][2] = {0};
    dp[k][1] = 1;
    rep(i, len){
        int nextdp[4][2] = {0};
        int num = n[i] - '0'; //上位i+1桁目の数字をチェック
        //cout << num << endl;
        //l=0側からの更新
        rep(k_itr, k){
            nextdp[k_itr][0] += dp[k_itr+1][0] * 9;
        }
        rep(k_itr, k+1){
            nextdp[k_itr][0] += dp[k_itr][0];
        } 
        //l=1側からの更新
        //l=1を維持
        if (num != 0){
            rep(k_itr, k) nextdp[k_itr][1] = dp[k_itr+1][1];
        } else{
            rep(k_itr, k+1) nextdp[k_itr][1] = dp[k_itr][1];
        }
        
        //l=0に推移
        rep(k_itr, k) nextdp[k_itr][0] += max(num - 1, 0) * dp[k_itr+1][1]; //1以上の数で推移
        if (num != 0) rep(k_itr, k+1) nextdp[k_itr][0] += dp[k_itr][1]; //0で推移
    
        memcpy(dp, nextdp, sizeof(nextdp));

    }


    cout << dp[0][0] + dp[0][1] << endl;
    

}

