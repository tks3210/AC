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



const int n_max = 200500;
vector<bool> visited(n_max, false);
vector<int> a;

void loop_search(int v, vector<int>& root, int &back){
    visited[v] = true;
    root.push_back(v);
    if (visited[a[v]] == true){
        back = a[v];
        return;
    } else {
        loop_search(a[v], root, back);
    }
    return;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp-1);}

    vector<int> root; //開始位置
    int back; //visitedで戻ったnode
    loop_search(0, root, back);

    // show(root);
    // cout << back << endl;

    ll back_no = 0;
    rep(i, root.size()){
        if (back == root[i]){
            back_no = i;            
        }
    }
    back_no++;

    int ans = 0;
    int len = root.size();
    ll loop_num = root.size()-back_no+1;

    // cout << endl;
    // cout << len << endl; //5
    // cout << back_no << endl; //3
    // cout << loop_num << endl; //2

    if (k >= (ll)root.size()){
        ll plus_loop = (k+1-back_no)%loop_num;
        // cout << plus_loop << endl;
        // cout << back_no+plus_loop-1 << "g"<< root[back_no+plus_loop-1]<< endl;
        ans = root[back_no+plus_loop-1];
    } else {
        ans = root[k];
    }

    if (a[0] == 0){
        cout << "1"<< endl;
        return 0;
    }

    cout << ans+1 << endl;

}

