#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    int n,k;
    cin >> n >> k;

    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        double ans_i = 1.0/n;
        int now = i;
        while(now < k){
            now *= 2;
            ans_i /= 2.0;
        }
        ans += ans_i;
    }
    printf("%.12f\n", ans);
}

