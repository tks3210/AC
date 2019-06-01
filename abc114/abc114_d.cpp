#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int k[101] = {0};

int main()
{
    int n;
    cin >> n;
    //素因数分解
    for (int i = 2; i <= n; i++)
    {
        int amari = i;
        for (int j = 2; j * j <= amari; j++)
        {
            if (amari % j == 0)
            {
                while (amari % j == 0)
                {
                    amari /= j;
                    k[j]++;
                }
            }
        }
        k[amari]++;
    }

    int ans = 0;

    for (int i = 2; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int l = 2; l < n; l++)
            {
                if (k[i] >= 4){
                    int tmp1 = k[i];
                    k[i] += 1;
                    k[i] /= 5;
                    k[i] -= 1;
                    if(k[j] >= 4){
                        int tmp2 = k[j];
                        k[j] += 1;
                        k[j] /= 5;
                        k[j] -= 1;
                        if(k[l] >= 2){
                            ans++;
                        }
                        k[j] = tmp2;
                    }
                    k[i] = tmp1;
                }
            }
        }
    }

    cout << ans << endl;
}