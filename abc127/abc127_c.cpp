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
    int n, m;
    cin >> n >> m;
    vector<int> l, r;
    rep(i, m){ 
        int tmpl, tmpr; 
        cin >> tmpl >> tmpr;
        l.push_back(tmpl);
        r.push_back(tmpr);
    }
    sort(l.begin(), l.end(), greater<int>());
    sort(r.begin(), r.end());

    int ans = 0;
    if(l[0] <= r[0]){
        ans = r[0] -l[0]+1;
    } 

    cout << ans << endl;
}


