#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

int nummap[10][10] = {0};

int main()
{
    int n;
    cin >> n;


    rep(i, n){
        int sento;
        int matu;
        int ip = i+1;
        matu = ip % 10;

        sento = ip;
        while(sento >= 10){
            sento /= 10;
        }
        nummap[sento][matu]++;
    }

    ll ans = 0;
    rep(i, 10){
    rep(j, 10){
        ans += nummap[i][j] * nummap[j][i];
        //cout << nummap[i][j] << " ";
    }
    //cout << endl;
    }
    cout << ans << endl;

}

