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
    int m , k;
    cin >> m >> k;

    if (m == 0){
        if (k == 0) {
            cout << 0 << " " << 0 << endl;
        } else {
            cout << -1 << endl;
        }
    } else if (m == 1){
        if (k == 0){
            cout << 0 << " " << 0 << " ";
            cout << 1 << " " << 1 << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        ll big = 1ll<<m;
        if (k >= big) {
            cout << -1 << endl;
            return 0;
        } 
        rep(i, big) {
            if (i == k) continue;
            cout << i << " ";
        }
        cout << k << " ";
        rep(i, big) { 
            if (big - (i+1) == k) continue;
            cout << big - (i+1) << " ";
        }
        cout << k << endl;
    }

    return 0;
}

