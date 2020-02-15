#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//ソート済の配列に対して、クエリの値がどこに当たるか調査。
//配列とクエリを入力、queryより小さい数字の最大値の位置を出力として返す。
//queryより小さい数字がない場合は-1を返す。
int func_ascending(vector<int>& input_arr, int query)
{
    if (query <= input_arr[input_arr.size() - 1]) return -1;
    return upper_bound(input_arr.begin(), input_arr.end(), query, greater<int>()) - input_arr.begin();
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
            //printf("%d %d %d\n", k, i , a[i]);
            b[k] = a[i];
        }

    }
    cout << b.size() << endl;

}