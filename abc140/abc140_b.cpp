#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}
    rep(i, n){ int tmp; cin >> tmp; b.push_back(tmp);}
    rep(i, n - 1){ int tmp; cin >> tmp; c.push_back(tmp);}

    int ans = 0;
    rep(i, n){
        ans += b[i];
        if (i != 0 && a[i] - a[i - 1] == 1){
            ans += c[a[i - 1] - 1];
        }
    }
    cout << ans << endl;

}



