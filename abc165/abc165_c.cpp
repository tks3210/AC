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

/*
全探索　数列生成

N,M,Qと4つの整数の組{ai, bi, ci, di}Q組が与えられる。
長さNの正数列であり、1<=A1<=A2<=...<=AN<=Mとなる数列Aに対して、
数列の得点を、
Abi - Aai = ciを満たすときdiが付加される。

数列の得点の最大値を求めたい。
N,M <= 10, Q<=50

N,Mが少ないので、全探索が可能？
20C10は100000程度

全探索の際の数列はfdsで生成

*/

struct query {
    int a,b,c,d;
    query(int a, int b, int c, int d) : a(a), b(b),c(c), d(d) {}
    bool operator<(const query& other) const {
        auto tmp = *this;
        if (tmp.a == other.a){
            return tmp.b < other.b;
        } else {
            return tmp.a < other.a;
        }
    }
};
vector<int> dp(10);

vector<vector<int>> num_array;
int n, m;
void fds(vector<vector<int>> &arr, vector<int> tmp = vector<int>()){
    // cout << tmp.size() << endl;
    // show(tmp);
    if (tmp.size() >= n){
        arr.push_back(tmp);
        return;
    }
    int st = 1;

    if (tmp.size() != 0){
        st = tmp[tmp.size()-1];
    }

    for (int i = st; i <= m; i++)
    {
        vector<int> t = tmp;
        t.push_back(i);
        fds(arr, t);
    }
    
    return;
}


int main()
{
    int q;
    cin >> n >> m >> q;
    vector<query> que;
    rep(i, q){ 
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--; b--;
        que.push_back({a, b, c, d});
    }

    fds(num_array);
    // rep(i, num_array.size()){
    //     show(num_array[i]);
    // }

    ll ans = 0;
    rep(i, num_array.size()){
        auto x = num_array[i];
        ll tans = 0;
        rep(j, q){
            if (x[que[j].a] + que[j].c == x[que[j].b]){
                tans += que[j].d;
            }
        }
        ans = max(tans, ans);
    }
    cout << ans << endl;
}

