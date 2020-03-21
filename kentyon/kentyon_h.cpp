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


int fib1(int n){
    vector<int> dp(n);
    dp[0] = 1;
    dp[1] = 1;
    rep(i, n){
        if (i <= 1) continue;
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n-1];
}

int memo[100] = {0};
int fib2(int n){
    if (n>100) return -1;
    if (n==0 ||n==1) return 1;
    if (memo[n] != 0) return memo[n];

    memo[n] = fib2(n-1)+fib2(n-2);
    return memo[n];
}



int main()
{
    int n;
    cin >> n;

    cout << fib1(n) << endl;
    cout << fib2(n-1) << endl;

}

