#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
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

template<class X> bool judge1(X arrValue, int user){
    return (arrValue >= (X)user);
}


int main()
{
    int n;
    cin >> n;
    vector<int> l;
    rep(i, n){ int tmp; cin >> tmp; l.push_back(tmp);}
    sort(l.begin(), l.end());
    //show(l);

    int ans = 0;
    for (int i = 0; i < l.size(); i++)
    {
        for (int j = i + 1; j < l.size(); j++)
        {
            int two_sum = l[i] + l[j];
            int youso =  binarySearch_latest(l, judge1, two_sum);
            ans += ((youso - j - 1) < 0) ? 0: (youso - j - 1); 
        }
        
    }
    cout << ans << endl;


}

