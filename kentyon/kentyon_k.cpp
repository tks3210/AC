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

#define SCORE_MAX 105
ll dp[SCORE_MAX][SCORE_MAX][SCORE_MAX];

//[hansei]WA: 条件の見落とし系
int main()
{
    int n, m;
    cin >> n >> m;
    rep(i, n){ 
        ll a,b,c,w; 
        cin >> a >> b >> c >> w; 
        dp[a][b][c] = max(w, dp[a][b][c]);
    }

    rep(i, SCORE_MAX)rep(j, SCORE_MAX)rep(k, SCORE_MAX){
        int id = (i==0)?0:i-1;
        int jd = (j==0)?0:j-1;
        int kd = (k==0)?0:k-1;
        dp[i][j][k] = max(max(dp[id][j][k],dp[i][jd][k]),max(dp[i][j][kd], dp[i][j][k]));
    }
    // rep(i,10){
    //     rep(j,10){
    //         rep(k,10){
    //             cout << dp[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl << "----------"<< endl;
    // }

    rep(i, m){
        int x,y,z; cin>>x>>y>>z;
        cout << dp[x][y][z] << endl;
    }
}

