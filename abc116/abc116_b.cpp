#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int ans = 4;
    while(1)
    {
        if (n == 1 || n == 2 || n == 4){
            break;
        }
        if (n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            n = 3 * n + 1;
        }
        ans++;
    }
    cout << ans << endl;
}