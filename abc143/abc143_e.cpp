#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)

#define INF 1001001001
typedef long long ll;


int main(){
    int n, m, l;
    cin >> n >> m >> l;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    rep(i, n) dist[i][i] = 0;
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = dist[b][a] = c;
    }

    rep(k, n)rep(i, n)rep(j, n) dist[i][j]= min(dist[i][j], dist[i][k] + dist[k][j]);

    vector<vector<int>> dist2(n, vector<int>(n, INF));
    rep(i, n)rep(j, n){
        if (dist[i][j] <= l){
            dist2[i][j] = 1;
        }
    }
    
    rep(k, n)rep(i, n)rep(j, n) dist2[i][j]= min(dist2[i][j], dist2[i][k] + dist2[k][j]);
    int q;
    cin >> q;
    rep(i, q){
        int s, t;
        cin >> s >> t;
        --s; --t;
        if (dist2[s][t] == INF){
            cout << "-1" << endl;
        } else {
            cout << dist2[s][t] - 1 << endl;
        }
    }
}


/* 
隣接リスト表現する
priority queで探索する

ダイクストラ法の距離に基づいて更新する部分を
＝＞給油回数と残油量に置き換えれば。。。


ワーシャルフロイド⇒燃料以下を１、燃料以上をＩＮＦとする⇒ワーシャルフロイド

データ構造
　隣接行列表現

*/