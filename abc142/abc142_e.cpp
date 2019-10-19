#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

#define MAX_NUM 1 << 12

int status[MAX_NUM] = {0};

vector<int> bitNumSorted(int n){

    vector<vector <int>> tmp(n + 1);
    int max = 1 << n;
    rep(i, max){
        int j = i;
        int bitn = 0;
        while(j > 0){
            if (j % 2 != 0) bitn++;
            j >>= 1;
        }
//        cout << i << bitn << endl;
        tmp[bitn].push_back(i);
    }
    vector<int> ans;
    rep(i, n + 1){
        for(auto x: tmp[i]) {ans.push_back(x);}
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    vector<int> c;

    rep(i, m){ 
        int tmp; cin >> tmp; a.push_back(tmp);
        int tmp_b; cin >> tmp_b;
        int c_bit = 0;
        rep(j, tmp_b){
            int tmp_c; cin >> tmp_c;
            c_bit += (1 << (tmp_c - 1));
        }
        c.push_back(c_bit);
    }

    //show(bitNumSorted(n));

    status[0] = 0;
    for (auto x: bitNumSorted(n))
    {
        if (status[x] == 0 && x != 0) continue;
        for (int i = 0; i < m; i++)
        {
            int tmp = x | c[i];
            if (status[tmp] == 0){
                status[tmp] = status[x] + a[i];
            } else {
                status[tmp] = min(status[tmp], status[x] + a[i]);
            }
        }
    }
        
    cout << (status[(1 << n) - 1] == 0 ? -1 : status[(1 << n) - 1]) << endl;   

}


/*
bitDPっぽい

Nが12しかないので2^Nの計算量が許容される

開けられる宝箱の状態をbitで表すと12bit 2^N個あり、
書く状態に対して必要な費用の最小値を算出する。

状態遷移の仕方は、鍵の種類に依存。
　分散型　ある地点から可能な遷移をメモ、不可能な状態は無視
　
辿る順番は、遷移の逆順を取らないことが補償されればよい。
よって、
0000 
0001 0010 0100 1000
0011 0101 1001 1010 0110 1100
0111 1011 1101 1110
1111
の辿り方（どうやって実装しよう？）

①上記の順序を担保するvector配列を作成
②状態を-1で初期化。0000のみ0にしておく。
③上記の順序のvector配列でforeachかける
　　foreach内で、下記の処理
　　-1ならばcontinue
      でなければMパターンの推移処理
      　　要素にMを足した要素を更新する　　
　　　　　　　費用は-1を除外したminを取る。
*/
