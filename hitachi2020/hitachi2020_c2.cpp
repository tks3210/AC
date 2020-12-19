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


const int n_max = 200050;
vector<vector<int>> tree(n_max);

void bfs(vector<int> &bin){
    int start = 0;

    queue<int> q;
    q.push(start);
    bin[start] = 1;
    while (!q.empty()){
        int now = q.front(); q.pop();
        for(auto next: tree[now]){
            if (bin[next] != 0) continue;
            bin[next] = -bin[now];
            q.push(next);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> bin(n_max, 0);
    bfs(bin);

    vector<int> plus;
    vector<int> minus;

    rep(i, n){
        if (bin[i] == 1) plus.push_back(i);
        else minus.push_back(i);
    }
    int plus_num = plus.size();
    int minus_num = minus.size();
    int div3_num = n/3;

    if (plus_num <= n/3 || minus_num <= n/3){

    } else {
        




    }




}
