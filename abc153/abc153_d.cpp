#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    ll h;
    cin >> h;

    int ans_sub = 0;
    while(h != 1){
        h >>= 1;
        ans_sub++;
    }

    ll ans = 1ll<<(ans_sub+1);
    ans -= 1;

 
   cout << ans << endl;
}

