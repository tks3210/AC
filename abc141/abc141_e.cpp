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

#define N_MAX 5050
int n;

int dp[N_MAX][N_MAX];

int main()
{
    int n;
    string s;
    cin >> n >> s;
    
    int ans = 0;
    rep(i, n)rep(j, n){
        if(s[i] == s[j]){
            if (abs(i-j) > dp[i][j]) dp[i+1][j+1] = dp[i][j] + 1; 
        }
        ans = max(dp[i+1][j+1], ans);
    }
    // rep(i, n+1){
    //     rep(j, n+1){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << ans << endl;
}

