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


#define N_MAX 1010

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> p;
    p.push_back(0);
    rep(i, n) {int tmp; cin >> tmp; p.push_back(tmp);}
    vector<ll> p2;
    rep(i, n+1)rep(j, n+1) p2.push_back(p[i]+p[j]);
    sort(p2.begin(), p2.end(), greater<ll>());

    ll ans = 0;
    rep(i, (n+1)*(n+1)){
        int ab = p2[i];
        int diff = m - ab;
        if (diff < 0) continue;
        auto itr = lower_bound(p2.begin(), p2.end(), diff, greater<ll>());
        ans = max(*itr + ab, ans);
    }

    cout << ans << endl;

}
/*
一見dpっぽいが多分解けない。
dp[i] = i番目の数字を表現して、あと使える数字の最大数
だとO(mn)かかるはず。

4回固定という点に着目
2回の合計を全列挙しても10^6(正確には1001 * 1001)
全列挙数列p2をソートして、
全列挙数列p2を最初から見ていき、m-p2[i]をキーとして全列挙数列p2の降順lower_boundを取る
帰ってきた値と、p2[i]との和が、p2[i]を使った条件下での最大値
*/

