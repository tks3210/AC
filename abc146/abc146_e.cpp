#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    vector<ll> sum_a;
    sum_a.push_back(0);

    ll sum_tmp = 0;
    rep(i, n){ 
        int tmp; 
        cin >> tmp;
        sum_tmp += tmp;
        sum_a.push_back(sum_tmp);
    }

    map<int, int> amari;
//    rep(i, k) amari.insert(make_pair(i, 0));

    //show(sum_a);
 
    ll ans = 0;
    for (int j = 1; j <= n; j++)
    {
        int itr = (sum_a[j] - (ll)j) % (ll)k;


        int itr_plus = (sum_a[j - 1] - (ll)(j - 1)) % (ll)k;
        if (amari.count(itr_plus) == 0) amari.insert(make_pair(itr_plus, 0));
        amari[itr_plus]++;

        if ((j - k) >= 0) {
            int itr_minus = (sum_a[j - k] - (ll)(j - k)) % (ll)k;   
            if (amari.count(itr_minus) == 0) amari.insert(make_pair(itr_minus, 0));
            amari[itr_minus]--;
        }
        //cout << itr << " "<< amari[itr] << endl;
        if (amari.count(itr) == 0) amari.insert(make_pair(itr, 0));
        ans += amari[itr];

    }
    

    cout << ans << endl;

}

/*

部分列の列挙でO(N^2)、和の取得にO(N)かかる。
セグメント木等を使っても、O(logN)
⇒累積和使ったらO(1)だよ＞＜

⇒median of medianでみたかも・・・

aの列を累積和 % Kで持つ

00
0 ~ k-1 をkey, valueを0とするmap構造
for(j = 1:N)
    s[j] - j 
    
    mapにs[j-1] - (j-1)を+1
    j-k >= 0のとき
    mapにs[j-k] - (j+1)を-1

    mapの中のs[j] - j の要素を足す


部分列の全パターンを確認する系は、
条件を満たすSum[j]とSum[i]を組み合わせを探す問題に帰着させ、
jを固定した後の導出結果から
j+1の導出につなげると効果的。

*/