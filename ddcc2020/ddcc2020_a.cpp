#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;


int main()
{
    int x[2];
    cin >> x[0] >> x[1];

    int ans = 0;
    rep(i, 2){
        if(x[i] == 1){
            ans += 300000;
        } else if(x[i] == 2){
            ans += 200000;
        } else if(x[i] == 3){
            ans += 100000;
        }
    }

    if (ans == 600000){
        ans = 1000000;
    }

    cout << ans << endl;
}

