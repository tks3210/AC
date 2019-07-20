#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

int main()
{
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }


    for (int i = 0; i < n; i++)
    {
        if (i == 0){
            b.push_back(a[i]);
            continue;
        }

        //どの数字b[]よりも小さい場合
        if (b[b.size() - 1] >= a[i]){
            b.push_back(a[i]);
        } else {
            int k = func_ascending(b, a[i]);
            //printf("%d %d %d", k, i , a[i]);
            b[k] = a[i];
        }

    }
    cout << b.size() << endl;

}