#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

struct Edge{
    int to, id;
    Edge(int to, int id): to(to), id(id){} 
};

vector<Edge> edge[52];
//vector<int> a    :int要素を格納するまっさらな動的配列
//vector<int> a(5) :予め5個のint要素を確保した動的配列
//vector<int> a[5] :まっさらな動的配列を5つ確保している静的配列

bool fds(vector<int>& root, int now, int targ, int parent){
    if (targ == now){
        return true;
    }
    for (auto next : edge[now]){
        if (next.to == parent) continue;
        if (fds(root, next.to, targ, now)){
            root.push_back(next.id);
            return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n;
    
    rep(i, n-1){
        int tmpa, tmpb; cin >> tmpa >> tmpb;
        tmpa--; tmpb--;
        edge[tmpa].emplace_back(tmpb, i);
        edge[tmpb].emplace_back(tmpa, i);
    }    

    cin >> m;
    vector<ll> bitmap_range(m);
    rep(i, m){
        int tmpa, tmpb; cin >> tmpa >> tmpb;
        tmpa--; tmpb--;
        vector<int> root;
        fds(root, tmpa, tmpb, -1);
        // cout << i << ":";
        // show(root);
        // cout << endl;
        for(auto hen:root){
            bitmap_range[i] += 1ll << hen;            
        }
    }
    ll ans = 0;
    rep(i, 1<<m){
        ll score;
        ll sum_range = 0;
        rep(j, m){
            if (i>>j&1) sum_range |= bitmap_range[j];
        }
        score = 1ll<<(n-1-__builtin_popcountll(sum_range));
        if (__builtin_popcountll(i)%2 == 0){
            ans += score;
        } else {
            ans -= score;
        }
        //cout << score << endl;
    }

    cout << ans << endl;
}