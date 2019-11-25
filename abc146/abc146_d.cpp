#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;


typedef struct {
    int start;
    int end;
} lineInfo_t;

//map内のソート基準を規定
bool operator<(const lineInfo_t &lhs, const lineInfo_t &rhs){
    if (lhs.start == rhs.start){
        return lhs.end < rhs.end;
    } else {
        return lhs.start < rhs.start;
    }
}

map<lineInfo_t, int> lineinfo; //key:辺,value:色

int dfs(int parent, int node, int usedColor, vector<vector<int>>& g){
    int maxColor = 0;
    if (node != 0 && g[node].size() == 1) return 1;
    int tmpColor = 1;
    for (auto line: g[node]){
        if (line == parent) continue;
        if (tmpColor == usedColor) tmpColor++;
        lineInfo_t tmpline = {node, line};
        //cout << tmpline.start << " " << tmpline.end << " " <<tmpColor << endl;
        lineinfo.insert(make_pair(tmpline, tmpColor));
        maxColor = max(maxColor, dfs(node, line, tmpColor, g));
        tmpColor++;
    }
    return max(maxColor, (int)g[node].size());
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> line;
    vector<vector<int>> g(n);
    rep(i, n - 1){
        int tmpa, tmpb;
        cin >> tmpa >> tmpb;
        tmpa--; tmpb--;
        g[tmpa].push_back(tmpb);
        g[tmpb].push_back(tmpa);
        line.push_back(make_pair(tmpa, tmpb));
    }
    //parent: 初期値は存在しない(-1), node:開始位置, usedColor:使用色(0), map:g
    int size = dfs(-1, 0, 0, g);

    cout << size << endl;
    for (auto l: line){
        if (lineinfo.count({l.first, l.second}) == 0){ cout << "none" << endl;}
        cout << lineinfo[{l.first, l.second}] << endl;
    }
}

/*
    木：Ｎ頂点とＮ－１の辺からなるグラフ。
    深さ優先探索により、頂点から辿っていく。
       現在のノード、使用した色
    
    辺の色を規定するのは容易
　　　辺a-bの色はx　　　
    それをどうやって出力する？

    配列にするとn^2 = 10^10を超えてアウト
    vectorにすると探索時間でn超えてアウト
    mapで管理しよう！


    fdsで辺の色を記録⇒ソート。
    クエリ時に二分探索で対応する辺を探し出力

*/