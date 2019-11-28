#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main()
{
    int a, b;
    cin >> a >> b;

    int ans = (a < 2*b) ? 0 : a - 2*b;
    cout << ans << endl;
    
}

