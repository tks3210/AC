#include <iostream>
#include <vector>
using namespace std;

//pair<int int> 二つの異なる型の値を保持する。
//メンバ変数としてfirst, secondを持つ。XX.firstみたいな感じでアクセスする。
//https://cpprefjp.github.io/reference/utility/pair.html
#define pir pair<int, int>
//vector<T> 動的配列。
//不定個数の要素を格納できる。push_back()で要素を追加する。
vector<pair<pir,pir>> ans;
int main(){
    int H, W;
    int tmp;
    int Num[500][500] = {0};

    cin >> H >> W;

    for (int i= 0; i < H; i++){
        for (int j=0; j < W; j++){
            if (i == H - 1 && j == W - 1) break;
            cin >> tmp;
            Num[i][j] += tmp;
            if (Num[i][j] % 2 != 0){
                if (j != W - 1){
                    //make_pair(T1, T2) によりpairクラスのオブジェクトを生成できる。
                    ans.push_back(make_pair(make_pair(i+1, j+1), make_pair(i+1, j+2)));
                    Num[i][j+1]++;
                }else {
                    //なんやかんやこれでも、push_backできるらしい。波括弧の初期化
                    //https://dev.activebasic.com/egtra/2015/12/02/845/
                    ans.push_back({{i+1, j+1}, {i+2, j+1}});
                    Num[i+1][j]++;
                }
            } 
        }
    }
    cout << ans.size() << endl;
    //範囲for文 コンテナ内の全要素に関してループを行う。　
    //(下の例だとansのクラスの)メンバ関数にbegin(),end()を持つクラスであれば使用可能
    //https://cpprefjp.github.io/lang/cpp11/range_based_for.html
    for (auto p:ans){
        cout << p.first.first << " " << p.first.second << " " << p.second.first << " " << p.second.second << endl;
    }
}