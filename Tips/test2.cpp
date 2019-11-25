#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//50x50(端を含む)サイズを確保
char map[52][52];

int score(string x){

    int num = stoi(x);

    bool isSosu = true;
    for(int i = 2; i*i <= num; i++)
    {
        if (num % i == 0){
            isSosu = false;
        }
    }
    if (num == 2) isSosu = true;
    if (num == 1) isSosu = false;

    if (!isSosu) return 0;

    int mut = 1;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '0') {
            mut++;
            break;
        }
    }
    string y = x;
    reverse(y.begin(), y.end());
    if (x == y){
        mut++;
    }

    return num*mut;
}


void show(){
    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void init(int n, int m){

    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            map[i][j] = '.';
        }
    }


    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char tmp; cin >> tmp;
            map[i][j] = tmp;
        }        
    }
    
    //show();
}

void fds(int row, int col, string nowStr, vector<pair<int, int>> isWalk, vector<string>& result){
    if (nowStr != "") result.push_back(nowStr);
    if (isWalk.size() == 4) {
        return;
    }
    int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    for (int i = 0; i < 4; i++)
    {
        int rownext = row + move[i][0]; 
        int colnext = col + move[i][1];
        bool isPass = false; 
        for (auto p: isWalk)  {
            if (p.first == rownext && p.second == colnext){
                isPass = true;
            }
        }
        vector<pair<int, int>> isWalknext;
        isWalknext = isWalk;
        if (isPass == false && map[rownext][colnext] != '.'){
            isWalknext.push_back(make_pair(row, col)); 
            fds(rownext, colnext, nowStr + map[rownext][colnext], isWalknext, result);    
        }
    }
    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    init(n, m);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] == '.' || map[i][j] == '0') continue;
            vector<string> res; 
            vector<pair<int, int>> isWalk;
            string start = "";
            start += map[i][j];
            fds(i, j, start, isWalk, res);
            for (int k = 0; k < res.size(); k++)
            {
                //cout << "[str]" << i << " "<< j << " " << res[k] << " "<< score(res[k]) << endl;
                ans = max(ans, score(res[k]));
            }
        }
    }

    cout << ans << endl;

}

/*
n, m = 50
・map作成
・経路の5桁文字列全列挙(深さ優先探索)
   O(N^2 * 4^5)?
   
   現在位置(x, y)
   あと何マス進めるか
　 通った情報(global)
   現在の数字列
   進めない場合or5文字完成の場合はvectorに格納
   進まない場合もvectorに格納する必要がある。
   結果はvectorに格納



・スコア算出

*/