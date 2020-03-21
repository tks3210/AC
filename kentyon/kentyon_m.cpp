#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF (ll)10e15
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

int n, w;
#define MAX_N 205
#define MAX_COL 1005
vector<vector<ll>> dp(MAX_N, vector<ll>(MAX_COL*MAX_N, 0));

ll all_calc(vector<P> &bag){
    
    vector<Pl> sum_half_f;
    rep(i, 1<<n/2){
        ll sum_v = 0;
        ll sum_w = 0;
        rep(j, n){
            //[hansei]bitの判定は(i>>j)==1じゃないよ
            if((i>>j)&1){
                sum_v+=bag[j].first;
                sum_w+=bag[j].second;
            }
        }
        sum_half_f.push_back({sum_w, sum_v});
    }
    vector<Pl> sum_half_l;
    rep(i, 1<<n-(n/2)){
        ll sum_v = 0;
        ll sum_w = 0;
        rep(j, n){
            if((i>>j)&1){
                sum_v+=bag[j+(n/2)].first;
                sum_w+=bag[j+(n/2)].second;
            }
        }
        sum_half_l.push_back({sum_w, sum_v});
    }
    sort(sum_half_f.begin(), sum_half_f.end());
    ll max_value = 0;
    rep(i, sum_half_f.size()){
        max_value = max(max_value, sum_half_f[i].second);
        sum_half_f[i].second = max_value;
    }
    // rep(i, sum_half_f.size()){
    //     cout << sum_half_f[i].first << ":" << sum_half_f[i].second << endl;
    // }
    // rep(i, sum_half_l.size()){
    //     cout << sum_half_l[i].first << ":" << sum_half_l[i].second << endl;
    // }



    ll ans = 0;
    rep(i, sum_half_l.size()){
        ll remain = w - sum_half_l[i].first; 
        if (remain < 0) continue;
        int l = -1;
        int r = sum_half_f.size();
        while(abs(r-l)>1){
            int mid = (l+r)/2;
            if (sum_half_f[mid].first <= remain) l = mid;
            else r = mid;
        }
        ans = max(sum_half_l[i].second+sum_half_f[l].second, ans);
    }

    return ans;
}

//重さをキーとした価値最大化
ll weight_dp(vector<P> &bag){
    rep(i, n){
        rep(j, MAX_COL*MAX_N){
            if (j>=bag[i].second){
                dp[i+1][j] = max(dp[i][j], dp[i][j-bag[i].second]+bag[i].first); 
            } else {
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    return dp[n][min(w, MAX_COL*MAX_N-1)];
}

//価値をキーとした重さ最小化
ll value_dp(vector<P> &bag){
    rep(i, n+1)rep(j, MAX_COL*MAX_N){ dp[i][j] = INF;}
    dp[0][0] = 0;
    rep(i, n){
        rep(j, MAX_COL*MAX_N){
            dp[i+1][j] = min(dp[i][j], dp[i][max(0, j-bag[i].first)]+bag[i].second);
        }
    }
    int ans = 0;
    int value = 0;
    rep(i, n) value+=bag[i].first;
    rep(i, MAX_COL*MAX_N){
        //cout << dp[n][i] << endl;
        if (dp[n][i]<=w){ans = i;}
        else { break; }
    }
    return min(ans,value);
}

int main()
{
    cin >> n >> w;
    vector<P> bag(n);
    int min_value = 0;
    int min_weight = 0;
    rep(i, n){ 
        cin >> bag[i].first >> bag[i].second;
        min_value = max(min_value, bag[i].first);
        min_weight = max(min_weight, bag[i].second);
    }

    ll ans = 0;
    if (n <= 30){
        ans = all_calc(bag);
    } else if (min_value <= 1000){
        //価値をキーとして重さ最小化
        ans = value_dp(bag);
    } else if (min_weight <= 1000){
        //重さをキーとした価値最大化
        ans = weight_dp(bag);
    }
    cout << ans << endl;
}

