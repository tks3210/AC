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
    ll w, h, x, y;
    cin >> w >> h >> x >> y;

    double ans1 = (double)(w * h) / 2.0; 
    int ans2 = 0; 
    if (x == (w/2) && y == (h/2) && w%2 == 0 && h%2 == 0){
        ans2 = 1;
    }
    cout << ans1 << " " << ans2 << endl;
}

