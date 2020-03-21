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

const int N_MAX = 10050;
const int M_MAX = 1050;

vector<vector<int>> dp(N_MAX, vector<int>(M_MAX, -1));
int main()
{
    int n, m, l, x;
    cin >> n >> m >> l >> x;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}

    dp[0][0] = x;
    rep(i, n){
        rep(j, m){
            dp[i+1][j] = max(dp[i][(j-a[i]%m+m)%m]-(a[i]/m + (a[i]%m > j)), dp[i][j]);
        }
    }
    bool ans = false;
    rep(i, n+1){
        if (dp[i][l] > 0){
            ans = true;
            break;
        }
    }

    // rep(i, n+1){
    //     rep(j, m){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

