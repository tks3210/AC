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

int grid[2010][2010] = {0};
int sum[2010][2010] = {0};

int main()
{
    int n, k;
    cin >> n >> k;

    rep(i, n){ 
        int x, y; char c; bool z; 
        cin >> x >> y >> c;
        if (c=='W') z = false;
        else z = true;
        int dx = x%(2*k);
        int dy = y%(2*k);
        if (!z) dx = (dx+k)%(2*k);
        grid[dx][dy]++;
    }

    rep(i, 2*k){
        rep(j, 2*k){
            sum[i+1][j+1]=sum[i+1][j]+sum[i][j+1]-sum[i][j]+grid[i][j];
        }
    }

    // rep(i, 2*k){
    //     rep(j, 2*k){
    //         cout << grid[i][j] << ":";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // rep(i, 2*k){
    //     rep(j, 2*k){
    //         cout << sum[i+1][j+1] << ":";
    //     }
    //     cout << endl;
    // }
    int ans_max = 0;
    //[hansei] 探索範囲の誤り
    rep(i, k+1){
        rep(j, k+1){
            // ans += sum[2*k][2*k] - sum[2*k][j+k] - sum[i+k][2*k];
            // ans += sum[2*k][j] + sum[i][2*k];
            // ans += (sum[i+k][j+k] - sum[i][j+k] - sum[i+k][j] + sum[i][j])*2;
            //cout << i << j << ":" << ans << endl;
            int tmp1=sum[i][j]+sum[0][0]-sum[i][0]-sum[0][j];
            int tmp2=sum[i+k][j+k]+sum[i][j]-sum[i+k][j]-sum[i][j+k];
            int tmp3=sum[2*k][2*k]+sum[i+k][j+k]-sum[2*k][j+k]-sum[i+k][2*k];
            int tmp4=sum[i][2*k]+sum[0][j+k]-sum[i][j+k]-sum[0][2*k];
            int tmp5=sum[2*k][j]+sum[i+k][0]-sum[2*k][0]-sum[i+k][j];
            int ans=tmp1+tmp2+tmp3+tmp4+tmp5;
            ans_max = max(ans_max, ans);
            //[hansei] 探索範囲の検討不足
            ans_max = max(ans_max, n-ans);
        }
    }
    cout << ans_max << endl;
}

