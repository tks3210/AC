#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main()
{
    int a, b;
    cin >> a >> b;

    if (a >= 1 && a <= 9 && b >= 1 && b <= 9){
        cout << a * b << endl;
    } else {
        cout << -1 << endl;
    }

}

