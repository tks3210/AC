#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

char cakemap[302][302];
int ansmap[302][302];

void paint(int row, int col, int num){

    pair<int, int> colarea = {col, col};
    pair<int, int> rowarea = {row, row};
    while(1){
        if (cakemap[row][colarea.first - 1] != '.') break;
        colarea.first--;
    }
    while(1){
        if (cakemap[row][colarea.second + 1] != '.') break;
        colarea.second++;
    }
    while(1){
        int brsign = 0;
        for (int i = colarea.first; i <= colarea.second; i++)
        {
            if (cakemap[rowarea.first - 1][i] != '.'){
                brsign = 1;
                break;
            }
        }
        if (brsign == 1) break;
        rowarea.first--;
    }
    while(1){
        int brsign = 0;
        for (int i = colarea.first; i <= colarea.second; i++)
        {
            if (cakemap[rowarea.second + 1][i] != '.'){
                brsign = 1;
                break;
            }
        }
        if (brsign == 1) break;
        rowarea.second++;
    }

    //printf("row[%d:%d], col[%d:%d]\n", rowarea.first, rowarea.second, colarea.first, colarea.second);
    for (int i = rowarea.first; i <= rowarea.second; i++)
    {
        for (int j = colarea.first; j <= colarea.second; j++)
        {
            cakemap[i][j] = 'X';
            ansmap[i][j] = num;
        }
    }
}


int main()
{
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<int>> line(h);

    rep(i, 302)rep(j,302){
        cakemap[i][j] = '#';
    }


    rep(i, h)rep(j, w){
        char tmp; cin >> tmp;
        if(tmp != '.') line[i].push_back(j);
        cakemap[i + 1][j + 1] = tmp;
    }

    
    int num = 1;
    rep(i, h){
        rep(j, w){
            if (cakemap[i + 1][j + 1] == '#'){
                paint(i+1, j+1, num);
                num++;
            }
        }
    }

    rep(i, h){
        rep(j, w){
            printf("%d ",ansmap[i+1][j+1]);
        }
        printf("\n");
    }
}



/*
1行ずつチェック
　#に到達、
　　今までの空きをその数字で埋める。
　　次の#に到達するまでその数字で埋める。
　　







*/