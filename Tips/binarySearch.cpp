#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


/* 判定式を指定できるめぐる式二分探索 */
/* input: arr:行列、callback:判定方法の関数ポインタ、 userQuery:判定に使用するための引数(省略可)*/
/* output: 条件を満たす要素の最小値(全て満たさなければ要素サイズを返す) */
/* 制約事項: 行列のある要素に対して判定方法callbackを満たすとき、それより大きな要素も判定方法を満たす必要がある。 */
template<class X> int binarySearch_latest(vector<X> arr, bool (*callback)(X, int), X userQuery = 0) {
    int ng = -1;
    int ok = (int)arr.size();
    while(abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;
        if (callback(arr[mid], userQuery)){ ok = mid; } else { ng = mid; }
    }
    return ok;
}

/* 判定方法1 */
/* input: arrValue:行列の要素、user:任意に指定した引数*/
/* 指定した値userがarrValueより小さいとき真を返す */
template<class X> bool judge1(X arrValue, int user){
    return (arrValue >= (X)user);
}

/* 判定方法2 */
/* input: arrValue:行列の要素、user:任意に指定した引数*/
/* 指定した値userの二乗がarrValueより小さいとき真を返す */
template<class X> bool judge2(X arrValue, int user){
    return (arrValue >= ((X)user*(X)user));
}


int main(){
    int a_data[] = {2, 4, 6, 8, 10, 45};
    vector<int> a(a_data, a_data + 6);
    for (int i = 0; i < 10; i++)
    {
        //printf("[%d] => %d  ",i, binarySearch_latest(a, judge1, i));
        //printf("[%d] => %d  \n",i, binarySearch_latest(a, judge2, i));
        int ans = 0;
        if ((ans = a[binarySearch_latest(a, judge1, i)]) != i){
            ans = -1;
        }
        printf("[%d] => %d  \n",i, ans);        
    }
}