#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>

#define min(x, y) (x > y ? y : x)
using namespace std;
vector<long long> num;

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }
    sort(num.begin(), num.end());

    int len = num.size();
    long long ans = 0;
    ans += abs(num[num.size() - 1] - num[0]);
    //printf("%d\n", ans);

    for (int i = 0; i < (len / 2) - 1; i++)
    {
        ans += abs(num[num.size() - 1 - i] - num[i + 1]);
        //printf("%d\n", ans);
        ans += abs(num[num.size() - 2 - i] - num[i]);
        //printf("%d\n", ans);
    }
    if (len % 2 == 1)
    {
        long long tmp1, tmp2;
        tmp1 = abs(num[len / 2] - num[len / 2 - 1]);
        tmp2 = abs(num[len / 2 + 1] - num[len / 2]);
        if (tmp1 <= tmp2)
        {
            ans += tmp2;
        }
        else
        {
            ans += tmp1;
        }
    }
    //printf("%d", ans);

    cout << ans << endl;
}