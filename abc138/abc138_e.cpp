#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

/* 判定式を指定できるめぐる式二分探索 */
/* input: arr:行列、callback:判定方法の関数ポインタ、 userQuery:判定に使用するための引数(省略可)*/
/* output: 条件を満たす要素の最小値(全て満たさなければ要素サイズを返す) */
/* 制約事項: 行列のある要素に対して判定方法callbackを満たすとき、それより大きな要素も判定方法を満たす必要がある。 */
template<class X> int binarySearch_latest(vector<X> &arr, bool (*callback)(X, int), X userQuery = 0) {
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
    return (arrValue > (X)user);
}


int main()
{
    string s,t;
    cin >> s;
    cin >> t;
    vector<vector<int>> alphamap(30);

    rep(i, s.size()){ 
        int a = s[i] - 'a';
        alphamap[a].push_back(i);
    }   

    ll ansloop = 0;
    int cnt = -1;
    rep(i, t.size()){
        //t[i]文字目を調査
        int targalpha = t[i] - 'a';
        if (alphamap[targalpha].size() == 0) {
            cout << "-1" << endl;
            return 0;
        }
        int add = binarySearch_latest(alphamap[targalpha], judge1, cnt);        
        if (add == alphamap[targalpha].size()){
            cnt = alphamap[targalpha][0];
            ansloop++;
        } else {
            cnt = alphamap[targalpha][add];
        }
    }
    ll ans = ((ll)ansloop * (ll)s.size()) + (ll)cnt + 1;
    cout << ans << endl; 
}

