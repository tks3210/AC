#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

struct Edge{
    int to, id;
    Edge(int to, int id): to(to), id(id) {}
};
vector<vector<Edge>> a(50);

/* 目的地までの経路を返す */
bool fds(int parent, int to, int from, vector<int>& root){
    if (from == to){
        return true;
    }
    for (auto edge : a[from])
    {
        if (parent == edge.to) continue;
        if (fds(from, to, edge.to, root)){
            root.push_back(edge.id);
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    rep(i, n-1){ 
        int tmp1, tmp2; cin >> tmp1 >> tmp2; 
        tmp1--; tmp2--;
        a[tmp1].emplace_back(tmp2, i);
        a[tmp2].emplace_back(tmp1, i);
    }
    int m;
    cin >> m;
    vector<pair<int, int>> u;
    rep(i, m){
        int tmp1, tmp2; cin >> tmp1 >> tmp2; 
        tmp1--; tmp2--;
        u.emplace_back(tmp1, tmp2);
    }

    // for(auto l: u){
    //     cout << l.first << l.second << endl;
    // }
    vector<ll> eset(m);
    rep(i, m){
        vector<int> root;
        fds(-1, u[i].first, u[i].second, root);
        //show(root);
        for (auto node: root){
            eset[i] |= 1ll<<node;
        }
    }

    ll ans = 0;
    //i bitでどの条件の集合をとるかを表す
    rep(i, 1<<m){
        ll mask = 0;
        //複数条件の積集合のカバー範囲を記載
        rep(j, m){
            if ((i>>j)&1 == 1){
                mask |= eset[j];
            }
        }
        int white = __builtin_popcountll(mask);
        ll now = 1ll<<(n-1-white);
        //cout << white << " "<< now << endl;
        if (__builtin_popcountll(i)%2 ==0) {
            ans += now;
        } else {
            ans -= now;
        }
    }
    cout << ans << endl;
    //show(root);
    //for(auto i: root){cout << i+1 << " ";}
}

