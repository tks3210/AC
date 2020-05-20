#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1001001001
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

const int mod = 998244353;

/*
数直線上にN台のロボットがあり、X_iの位置に存在する
このロボットを動かすとD_i動き、他のロボットと接触するとそのロボットも動く。
動いていないロボットの組み合わせ数を求める。
1 <= N <=2*10^5
-10^9 <= X <= 10^9
1 <= D <= 10^9


ロボットを頂点、影響範囲を有効辺とした有向グラフとして扱える？
辺の数が最大N^2個。厳しそう。
Union Found Treeでは？　頂点間の依存関係が消失する。
たとえば、
1=>2=>3=>4のように波及していくパターンと、
1=>2,3, 3=>4のように波及していくパターンで区別がつかない。

位置をソート⇒縮約し、
x[i]: i番のロボットがi+1 からx[i]番のロボットまでを直接動かす。
のように変換することは容易

そこから、i番のロボットから間接的にどこまで動かすか？を議論するためには、
Segment Treeを使い、[i, x[i]+1)の区間のmaxを後ろから求めていくことで実現される。

y[i]: i番のロボットがy[i]番のロボットまでを間接的に動かす。

dp[i] : i番目以降のロボットの取り得る組み合わせ数とすると、

dp[n] = 2  (最後のロボットを動かすか否か)
dp[i] = dp[i+1] + dp[y[i]+1]
のようにして、
dp[1](コード上ではdp[0])が答えとなる。

依存関係がデータ間にあるときは、依存関係の先のほうからもとめると上手くいくかも。


*/

struct SegmentTree {
private:
    int n;
    vector<int> node;
public:
    SegmentTree(vector<int> v){
        int sz = v.size();
        n = 1; while(n < sz) n*=2;
        node.resize(2*n-1, -1);
        for (int i = 0; i < sz; i++) node[i+n-1] = v[i];
        for (int i = n-2; i>=0; i--) node[i] =max(node[2*i+1], node[2*i+2]);
    }
    void update(int x, int val){
        x += (n-1);
        node[x] = val;
        while(x>0){
            x = (x-1)/2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }
    int getmax(int a, int b, int k=0, int l=0, int r=-1){
        if (r < 0) r=n;
        if (r <= a || b <= l) return -1;
        if (a <= l && r <= b) return node[k];
        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
    int getval(int x){
        x += (n-1);
        return node[x];
    }
};


struct Robot{
    ll x;
    ll range;
    Robot(ll x=0, ll range=0) : x(x), range(range){}
};

//例えば、a < bとしたとき昇順ソートとなる
bool cmp(const Robot &a, const Robot &b){
    return a.x < b.x;
}

int main(){
    int n; cin >> n;
    vector<Robot> rb(n);
    rep(i,n) {
        ll x, d; cin >> x >> d;
        rb[i] = {x, d};
    }
    sort(rb.begin(), rb.end(), cmp);

    vector<int> pos(n);
    rep(i, n) pos[i] = rb[i].x;

    vector<int> r(n);
    rep(i, n){
        r[i] = lower_bound(pos.begin(), pos.end(), pos[i] + rb[i].range) - pos.begin();
        r[i] -= 1;
    }

    //show(r);

    SegmentTree st(r);

    for (int i = n-1; i >= 0; i--)
    {
        int tmp = st.getmax(i, st.getval(i)+1);
        st.update(i, tmp);
    }
    
    // rep(i, n){
    //     cout <<i << "::" << st.getval(i) << endl;
    // }

    vector<ll> dp(n+1);
    dp[n] = 1;
    for (int i = n-1; i >= 0; i--)
    {
        dp[i] = dp[i+1] + dp[st.getval(i)+1];
        dp[i] %= mod;
        //cout << i << ":" << dp[i] << endl;
    }
    
    cout << dp[0] << endl;
}
