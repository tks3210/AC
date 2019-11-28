#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


//解説放送参考 setの使い方
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> idx(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;
    rep(i, n) idx[a[i]] = i;


    set<int> watchedNum;
    ll ans = 0;
    //a[x]:x番目の数字, idx[x]:xに大きい数字の順番(0始まり)
    for (int x = n - 1; x >= 0; x--)
    {
        int tmp = idx[x];
        watchedNum.insert(tmp);

        vector<int> l(2, -1);
        vector<int> r(2, n);
        {
            auto itr = watchedNum.find(tmp);
            for (int i = 0; i < 2; i++)
            {
                if (itr == watchedNum.begin()) break;
                itr--;
                l[i] = *itr;                
            }
        }
        {
            auto itr = watchedNum.find(tmp);
            for (int i = 0; i < 2; i++)
            {
                itr++;
                if (itr == watchedNum.end()) break;
                r[i] = *itr;
            }
        }
        vector<int> ls(2);
        vector<int> rs(2);
        ls[0] = tmp - l[0]; ls[1] = l[0] - l[1];
        rs[0] = r[0] - tmp; rs[1] = r[1] - r[0];
        ll c = (ll)(ls[0] * rs[1]) + (ll)(ls[1] * rs[0]);
        ans += c * (x + 1);   
    }

    cout << ans << endl;
}

