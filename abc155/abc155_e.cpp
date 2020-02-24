#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    string s;
    cin >> s;


    int ans = 0;
    vector<int> dp(2, 0);
    vector<int> old_dp(2, 0);
 
    rep(i, s.size()){
        int num = s[i] - '0';
        if (i == 0) {old_dp[0] = (10-num)+1; old_dp[1] = num; continue;}
        dp[0] = min(old_dp[0] + (10-num)-1, old_dp[1]+(10-num)+1);
        dp[1] = min(old_dp[0], old_dp[1]) + num;
        old_dp = dp;
    }
    cout << min(old_dp[0],old_dp[1]) << endl;
}

