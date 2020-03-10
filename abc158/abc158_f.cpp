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

struct SegmentTree{
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

struct robot
{
    int id;
    int pos;
    int range;
};

bool cmp(const robot &a, const robot &b){  
    return a.pos < b.pos;
}

int main()
{
    int n;
    cin >> n;
    vector<robot> a;
    rep(i, n){ 
        int  tp, tr;
        cin >>tp >> tr;
        robot r = {i, tp, tr};
        a.push_back(r);
    }
    sort(a.begin(), a.end(), cmp);

    vector<int> position;
    rep(i, n){
        position.push_back(a[i].pos);
    }
    vector<int> effect;
    rep(i, n){
        int x = lower_bound(position.begin(), position.end(), a[i].pos + a[i].range) - position.begin();
        effect.push_back(x-1);
    }
    SegmentTree st(effect);
    rep(i, n){
        int id = n-1-i;
        int val = st.getmax(id, effect[id]+1);
        st.update(id, val);
    }

    ll tmpmod = 998244353;
    vector<ll> dp(n+1);
    dp[n] = 1;
    rep(i, n){
        int id = n-1-i;
        dp[id] = dp[id+1] + dp[st.getval(id) + 1];
        dp[id] %= tmpmod;
    }
    cout << dp[0] << endl;

}

