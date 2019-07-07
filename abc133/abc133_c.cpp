#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int l, r, lmod, rmod, ldiv, rdiv;
    cin >> l >> r;

    lmod = l % 2019;
    rmod = r % 2019;
    ldiv = l / 2019;
    rdiv = r / 2019;
    int ans = 2019;
    if (lmod < rmod && ldiv == rdiv){
        for (int i = lmod; i < rmod + 1; i++)
        {
            for (int j = i + 1; j < rmod + 1; j++)
            {
                ans = min(ans, (i * j) % 2019);
            }
        }
    } else {
        ans = 0;
    }
    cout << ans << endl;
}

