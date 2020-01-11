#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

int n;

void bfs(int start, vector<int>& score, vector<vector<int>>& a){
    vector<bool> isSearch(n, false);
    queue<int> q;
    q.push(start);
    score[start] = 0;
    isSearch[start] = true;
    while(!q.empty()){
        int x = q.front();
        isSearch[x] = true;
        q.pop();
        for(auto l: a[x]){
            if (isSearch[l] == true) continue;
            q.push(l);
            score[l] = score[x] + 1;
        }
    }

}

int main()
{
    int u, v;
    cin >> n >> u >> v;
    u--; v--;
    vector<vector<int>> a(n);
    rep(i, n - 1){
        int tmpa, tmpb;
        cin >> tmpa >> tmpb;
        tmpa--; tmpb--;
        a[tmpa].push_back(tmpb);
        a[tmpb].push_back(tmpa);
    }

    vector<int> score_t(n), score_a(n);

    bfs(u, score_t, a);
    bfs(v, score_a, a);

    int ans = 0;
    rep(i,n){
        //cout << i+1 << ":" <<score[i].first << ":"<< score[i].second <<endl;
        if (score_t[i] < score_a[i]){
            ans = max(ans, score_a[i]);
        }
    }

    cout << max(ans - 1, 0) << endl;

}

