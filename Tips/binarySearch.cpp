#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//ソート済の配列に対して、クエリの値がどこに当たるか調査。
//配列とクエリを入力、queryより小さい数字の最大値の位置を出力として返す。
//queryより小さい数字がない場合は-1を返す。
int func_descending(vector<int> input_arr, int query)
{
    int l, r, mid;
    if (query <= input_arr[0]) return -1;
    //二分探索：開始位置は、l:0, r:末尾
    l = 0, r = input_arr.size() - 1;
    while(l <= r){
        mid = (l + r) / 2;
        if ((query > input_arr[mid]) && 
            ((mid == input_arr.size() - 1) || (query <= input_arr[mid + 1]))) {return mid;}
        else if (query <= input_arr[mid]){ r = mid;}
        else{ l = mid + 1;} //lの更新時は+1にしないと狭まらない
    }
}

//ソート済の配列に対して、クエリの値がどこに当たるか調査。
//配列とクエリを入力、queryより小さい数字の最大値の位置を出力として返す。
//queryより小さい数字がない場合は-1を返す。
int func_ascending(vector<int> input_arr, int query)
{
    int l, r, mid;
    if (query <= input_arr[input_arr.size() - 1]) return -1;
    //二分探索：開始位置は、l:0, r:末尾
    l = 0, r = input_arr.size() - 1;
    while(l <= r){
        mid = (l + r) / 2;
        if ((query > input_arr[mid]) && 
            ((mid == 0) || (query <= input_arr[mid - 1]))) {return mid;}
        else if (query <= input_arr[mid]){ l = mid + 1;}
        else{ r = mid;}
    }
}


int main(){
    int org_data[] = {2, 4, 6, 8, 10, 10, 12};
    vector<int> a(org_data, org_data + 7);

    for (int i = 0; i < 15; i++)
    {
        printf("[%d] => %d\n",i, func_descending(a, i));
    }

    sort(a.begin(), a.end(), greater<int>());

    for (int i = 0; i < 15; i++)
    {
        printf("[%d] => %d\n",i, func_ascending(a, i));
    }
 
}