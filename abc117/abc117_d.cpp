#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int onecnt[40] = {0};
int zerocnt[40] = {0};
ll allset[40] = {0};

ll calc_max(int num, int bit)
{

    ll tmp = 0;
    int next_num = num - (1 << bit);
    return max(calc_max(next_num, bit-1) + onecnt[bit]*(1<<bit), allset[bit - 1]);
}

int main()
{
    int n, k;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        ll tmp;
        cin >> tmp;
        int bit = 0;
        while (tmp != 0)
        {
            if (tmp % 2 == 1)
            {
                onecnt[bit]++;
            }
            else
            {
                zerocnt[bit]++;
            }
            tmp >>= 1;

            bit++;
        }
    }

    for (int i = 0; i < 40; i++)
    {
        //cout << onecnt[i] << " ";
    }

    for (int i = 0; i < 40; i++)
    {
        if (i == 0)
        {
            if (onecnt[i] < zerocnt[i])
            {
                allset[i] = zerocnt[i];
            }
            else
            {
                allset[i] = onecnt[i];
            }
            continue;
        }
        if (onecnt[i] < zerocnt[i])
        {
            allset[i] = zerocnt[i] * (1 << i) + allset[i - 1];
        }
        else
        {
            allset[i] = onecnt[i] * (1 << i) + allset[i - 1];
        }
    }

    int kbit = 0;
    while (k != 0)
    {
        k >>= 1;
        kbit++;
    }
    cout << calc_max(k, kbit) << endl;
}