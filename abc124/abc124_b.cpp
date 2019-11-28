#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    int hmax = 0;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (hmax <= tmp) ans++;
        hmax = max(hmax, tmp);
    }
    
    cout << ans << endl;

}

