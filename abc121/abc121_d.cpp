#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;


int main(){
    ll n, m;
    cin >> n >> m;

    int np4 = n % 4;
    int mp4 = m % 4;

    ll ans = 0;
    for(int i = np4; i < 4; i++)
    {
        ans = ans ^ n;
        n++;
    }
    for(int i = mp4; i >= 0; i--)
    {
        ans = ans ^ m;
        m--;
    }
    
    cout << ans;
}
