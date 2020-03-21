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


vector<vector<int>> dp(1050, vector<int>(10500, MOD));
int main()
{
    int h,n;
    cin >> h>> n;
    vector<P> ab(n);
    rep(i, n){ cin >> ab[i].first >> ab[i].second;}

    dp[0][0] = 0;
    rep(i,n){
        rep(j,h+1){
            dp[i+1][j] = min(dp[i][j], dp[i+1][max(0, j-ab[i].first)] + ab[i].second); 
        }
    }
    cout << dp[n][h] << endl;
}

