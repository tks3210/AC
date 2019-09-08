#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    vector<int> b;
    rep(i, n - 1){ int tmp; cin >> tmp; b.push_back(tmp);}

    int ans = b[0];
    for (int i = 0; i < b.size() - 1; i++)
    {
       ans += min(b[i], b[i+1]); 
    }
    ans += b[b.size() - 1];

    cout << ans << endl;

}

