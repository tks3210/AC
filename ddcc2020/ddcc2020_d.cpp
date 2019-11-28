#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;


int main()
{
    ll m;
    cin >> m;

    ll tmpmut = 0;
    ll ans = 0;
    rep(i, m){
        ll tmpc, tmpd;
        cin >> tmpd >> tmpc;
        tmpmut += tmpd * tmpc;
        ans += tmpc;
    }
    ans -= 1;

    ll amari = 0;
    while (tmpmut >= 10){
        amari = (tmpmut % 10);
        tmpmut /= 10;
        ans += tmpmut;
        tmpmut += amari;
    }

    printf("%lld\n",ans);

}

