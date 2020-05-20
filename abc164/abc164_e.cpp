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


const int n_max = 55;
vector<vector<int>> troot(n_max);

//v:現在の位置,rootall:v-goal間のすべての経路を格納, root/set 現在までの経路を格納
void dfs(int v, int goal,vector<vector<int>> &rootall, vector<int> root, set<int> sset, int sum){

    root.push_back(v);
    sset.insert(v);

    if (v == goal){
        rootall.push_back(root);
    }

    for(auto next: troot[v]){
        if (sset.find(next) == sset.end()){
            dfs(next, goal, rootall, root, sset, sum);
        }
    }


    return;
}


int main()
{
    int n, m;
    ll s;
    cin >> n >> m >> s;
    vector<P> root(m);
    vector<llP> cost(m);
    vector<P> change_cost(n); 
    rep(i, m){
        cin >> root[i].first >> root[i].second >> cost[i].first >> cost[i].second;
    }
    rep(i, n){
        cin >> change_cost[i].first >> change_cost[i].second;
    }

    rep(i, m){
        troot[root[i].first-1].push_back(root[i].second-1);
        troot[root[i].second-1].push_back(root[i].first-1);
    }

    for (int goal = 1; goal < n; goal++)
    {   
        vector<vector<int>> rall;
        vector<int> vkari;
        set<int> skari;
        dfs(0, goal, rall, vkari, skari);

        cout << goal << ":"<<endl;
        ll ans = (ll)MOD*50;
        for (auto r: rall)
        {
            for(auto x: r){

            }
        }        
    }
    


}

