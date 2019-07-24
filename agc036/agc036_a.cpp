#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


ll func_ascending(ll S)
{
    ll l, r, mid;
    l = 1, r = 1000000000;
    while(l <= r){
        ll tmp1, tmp2;
        mid = (l + r) / 2;
        tmp1 = mid * mid;
        tmp2 = (mid - 1) * (mid - 1);
        if ((S <= tmp1) && (S > tmp2)) {return mid;}
        else if (S > tmp1){ l = mid + 1;}
        else{ r = mid;}
    }
}



int main()
{
    ll S;
    cin >> S;
    ll N, D;
    /* 辺Nの決定 */
    N = func_ascending(S);
    /* 段Dの決定 */
    D = ((S - 1) / N) + 1;
    /* 第三点の決定 */    

    ll x1 = 0;
    ll y1 = 0;
    ll x2 = N;
    ll y2 = 1;
    ll x3 = N - (((S - 1)%N) + 1);
    ll y3 = D;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
}

