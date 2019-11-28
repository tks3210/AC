#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
#define PI 3.14159265359

int main()
{
    double a, b, x;
    cin >> a >> b >> x;

    double cup = a * a * b;
    double ans; 
    if (x > cup / 2){
        ans = atan2((cup - x),(a * a * a / 2));
    } else {
        ans = atan2((a * b * b / 2),x);
    }
    ans *= 180 / PI;
    printf("%3.10f\n", ans);

}

