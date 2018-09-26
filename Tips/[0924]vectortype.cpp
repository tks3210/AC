#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void out(vector<int> n){
    for(auto i:n){
        printf("%d ",i);
    }
    printf("\n");
}

int main(){
    //int型の仮想配列を宣言
    vector<int> n;
    int youso[5] ={2,6,7,1,3};
    for (int i = 0; i<5 ;i++){
        //仮想配列に要素を詰め込む
        n.push_back(youso[i]);
    }
    //最大値を最小値を*min_element(n.begin(),n.end())で出力
    cout << *max_element(n.begin(),n.end()) << " " << *min_element(n.begin(),n.end()) <<endl;

    //出力
    out(n);

    //昇順ソート
    sort(n.begin(),n.end());
    out(n);

    //降順ソート
    sort(n.begin(),n.end(),greater<int>());
    out(n);

}