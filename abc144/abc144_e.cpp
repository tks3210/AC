#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

vector<ll> a,f;
ll n;


ll binarySearch_latest(bool (*callback)(ll, ll), ll userQuery = 0) {
    ll ng = -1;
    ll ok = 10e12;
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        if (callback(mid, userQuery)){ ok = mid; } else { ng = mid; }
    }
    return ok;
}
bool judge1(ll arrValue, ll user){
    
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll sa = a[i]*f[i] - arrValue;
        if (sa <= 0) continue;
        ll tmp = sa / f[i];
        if (sa % f[i] != 0) tmp++;
        ans += tmp;
    }
    
    return ans <= user;
}


int main()
{
    ll k;
    cin >> n >> k;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}
    rep(i, n){ int tmp; cin >> tmp; f.push_back(tmp);}

    sort(a.begin(), a.end(), greater<ll>());
    sort(f.begin(), f.end());
    
    cout << binarySearch_latest(judge1, k) << endl;

}

/*
KのサイズがでかいのでオーダーにKを含めることはできない。
（K回ループを回すことはできない）

Aは降順、Fは昇順にして対応するのを担当するパターンが多分最適

理想的には、1/Fに対応する比率でAが分散するのが理想。小数計算は必須か？？

答えの候補の値 0 ~ 10^12を二分探索でいけるのでは・・・？

*/