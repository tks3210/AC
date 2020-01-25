#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;


int main()
{
    int a, b;
    cin >> a >> b;
    
    int minn = min(a, b);
    int maxn = max(a, b);

    rep(i, maxn) cout << minn;
    cout << endl;
}

