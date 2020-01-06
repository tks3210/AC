#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

/* 数列aの任意の二つの和に対して、xより大きい物の数を返す*/
ll query(int x, vector<int> &a){
    ll cnt = 0;
    rep(i, a.size()){
        cnt += a.end() - lower_bound(a.begin(), a.end(), x - a[i]);
    }
    return cnt;
}

ll sumans(int x, ll m, vector<int> &a){
    vector<ll> sum;
    ll s = 0;
    rep(i, a.size()){ sum.push_back(s); s += a[i]; }
    sum.push_back(s);

    ll ans = 0;
    ll shake_cnt = 0;
    rep(i, a.size()){
        int itr = lower_bound(a.begin(), a.end(), x - a[i]) - a.begin();
        ans += sum[a.size()] - sum[itr] + ((ll)a[i] * (a.size() - itr));
        shake_cnt += a.size() - itr;
    }
    if (shake_cnt > m) ans -= (ll)x*(shake_cnt - m);
    return ans;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}
    sort(a.begin(), a.end());
    //show(a);
    //cout << endl;
    //rep(i, 10) cout << i*10 << " " << query(i*10, a) << endl;

    int left = -1;
    int right = 200001;
    //入力mに対して、選ばれる数の下限を導出する
    //閾値を大きくすればmは減る
    while (abs(right - left) > 1){
        int mid = (left + right) / 2;
        if (m <= query(mid, a)){
            left = mid;
        } else {
            right = mid;
        }
    }
    //left以上の和がmパターン持つ事を補償している。
    //right以上の和がmパータン持たない事を補償している。
    //std::cout << "left:"<<left << endl;
    //std::cout << right << endl;

    std::cout << sumans(left, m, a) << endl;
}

