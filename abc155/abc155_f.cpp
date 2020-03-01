#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
#define ENTER cout<<endl
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;

ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}

#define NODE 100050
int visited[NODE] = {0};
vector<int> mid(NODE);
vector<vector<P>> line(NODE);
vector<int> ans;

int dfs(int n){
    visited[n] = 1;
    
    for(P next: line[n]){
        if(visited[next.first]) continue;
        int l = dfs(next.first);
        if(l) ans.push_back(next.second);
        mid[n] = mid[n]^l;
    }

    return mid[n];
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<Pl> ab(n);
    vector<Pll> lr(m);
    rep(i,n) cin >> ab[i].first >> ab[i].second;
    rep(i,m) cin >> lr[i].first >> lr[i].second;
    // rep(i, n){ ll tmpa; int tmpb; cin >> tmpa >> tmpb; ab[i]={tmpa, tmpb};}
    // rep(i, m){ ll tmpa; ll tmpb; cin >> tmpa >> tmpb; lr[i]={tmpa, tmpb};}

    sort(ab.begin(), ab.end());

    vector<int> bom(n+2);
    bom[0] = 0; bom[n+1] = 0;
    rep(i, n) bom[i+1] = ab[i].second;
    rep(i, n+1) mid[i] = bom[i] == bom[i+1] ? 0 : 1;

    vector<tuple<int, int, int>> range;
    rep(i, m) {
        int from = lower_bound(ab.begin(), ab.end(), Pl(lr[i].first, 0)) - ab.begin();
        int to = upper_bound(ab.begin(), ab.end(), Pl(lr[i].second, 1)) - ab.begin();
        int id = i+1; 
        range.emplace_back(from,to,id);
    }

    // show(bom);ENTER;
    // show(mid);ENTER;
    // rep(i, m) cout << get<0>(range[i]) << get<1>(range[i]) << endl;


    rep(i, m){
        int from, to, id;
        tie(from,to,id) = range[i];
        line[from].emplace_back(to, id);
        line[to].emplace_back(from, id);
    }

    rep(i, n+1){
        if(visited[i]==1) continue;
        if(dfs(i)) {puts("-1"); return 0;}
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    rep(i, ans.size()){
        cout << ans[i] <<" ";
    }
    return 0;
}

