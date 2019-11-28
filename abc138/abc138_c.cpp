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
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}
    sort(a.begin(), a.end(), greater<int>());

    double ans = 0;
    double tmp_div = 2.0;
    rep(i, n){
        ans += (double)a[i] / tmp_div;
        if (i != n-2) tmp_div *= 2.0;
    }
    cout << ans << endl;
}

