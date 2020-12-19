#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}


/*
上の硬貨から決めていくイメージ

4 44
1 4 20 100

①必要な金額Xに対して、A_i * k <= X < A_i*k+1になるようにkを選ぶ
 (Xが負の数の場合は、A_i * k < X <= A_i*k+1として負の数kを求める)
②k枚つかったパターンとk+1枚出すパターンを考慮し、Xから引く


*/
vector<ll> limit;
map<llP, int> memo;
ll dfs(ll remain, ll kouka, vector<ll>& value){
    //printf("%lld\n", remain);
    if (remain == 0) return 1;
    if (remain%value[kouka] == 0) return 1;
    if (memo.find(llP{remain, kouka}) != memo.end()) return memo[llP{remain, kouka}];
    ll maisu = remain/value[kouka];
    ll ans = 0;
    if (remain > 0){
        ans += dfs(remain-maisu*value[kouka], kouka-1, value);
        if (limit[kouka] >= maisu+1){
            ans += dfs(remain-(maisu+1)*value[kouka], kouka-1, value);
        } 
    } else {
        ans += dfs(remain-maisu*value[kouka], kouka-1, value);
        if (limit[kouka] >= abs(maisu-1)){
            ans += dfs(remain-(maisu-1)*value[kouka], kouka-1, value);
        }
    }
    memo[llP{remain, kouka}] = ans;
    return ans;
}

int main()
{
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    limit.assign(n, 1);
    rep(i, n){ cin >> a[i]; }

    rep(i, n-1){ limit[i] = a[i+1]/a[i] - 1; } 
    limit[n-1] = (x + a[n-1] - 1)/a[n-1];
    ll ans = dfs(x, n-1, a);

    cout << ans << endl;
}

