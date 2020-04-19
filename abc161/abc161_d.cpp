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

ll dp[30][10] = {0};

int main()
{
    int k;
    cin >> k;
    rep(i, 10) dp[0][i] = 1;

    rep(i, 30-1)rep(j, 10){
        dp[i+1][j] += dp[i][j];
        if (j != 9) dp[i+1][j] += dp[i][j+1];
        if (j != 0) dp[i+1][j] += dp[i][j-1];
    }


    // rep(i, 10){
    //     rep(j, 10){
    //     cout << dp[i][j] << " ";
    //     }
    //     cout << endl; 
    // }

    int it, jt;
    //k++; //0をテーブル上カウントしているため
    ll sum = 0;
    int rem = 0;
    rep(i, 29){
        int ok = false;
        rep(j, 10){
            if (j == 0) continue;
            sum += dp[i][j];
            if (sum >= k){
                it=i; jt=j; ok = true;
                rem = k-(sum-dp[i][j]);
                break;
            }
        }
        if (ok) break;
    }
    //cout << it << ":"<< jt << ":" << rem << endl;

    vector<int> ans;
    ans.push_back(jt);
    for(int i = it-1; i >= 0; i--){
        int tmprem = 0;
        if (jt != 0) tmprem += dp[i][jt-1];
        if (tmprem >= rem){
            //rem = rem;
            jt--; ans.push_back(jt); continue;
        }
        tmprem += dp[i][jt];
        if (tmprem >= rem){
            rem = rem - (tmprem - dp[i][jt]);
            ans.push_back(jt);continue;
        }
        if (jt != 9) tmprem += dp[i][jt+1];
        if (tmprem >= rem){
            rem = rem - (tmprem - dp[i][jt+1]);
            jt++; ans.push_back(jt);
        }
    }

    rep(i, ans.size()){
        cout << ans[i];
    }
    cout << endl;
}

