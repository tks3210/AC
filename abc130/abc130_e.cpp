#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

#define S 2005
#define T 2005
ll dp[S][T] = {0};
ll dp_sumCommonString(vector<int>& s, vector<int>& t){
    rep(i, s.size())rep(j, t.size()){
        if (s[i] == t[j]){
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] + 1;
        } else {
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j];
        }
        dp[i+1][j+1] %= MOD; 
    }
    return dp[s.size()][t.size()] + 1;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    vector<int> t(m);    
    rep(i, n) {int tmp; cin >> tmp; s[i] = tmp;}
    rep(j, m) {int tmp; cin >> tmp; t[j] = tmp;}
    cout << dp_sumCommonString(s, t) << endl; 
}