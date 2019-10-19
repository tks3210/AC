#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    string s; cin >> s;

    char bef = 0;
    int ans = 0;
    rep(i, n){
        if (bef != s[i]) ans++;
        bef = s[i];
    }
    cout << ans << endl;
}

