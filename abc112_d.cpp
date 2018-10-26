#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

typedef pair<int, int> P;
vector<P> soinsu;
#define INF 1000001
#define min(x, y) (x > y ? y : x)
int calcmem[INF] = {0};

int checkmin(int num)
{
    if (num == 1) return soinsu[0].first;
    for (auto i : soinsu)
    {
        if (num % i.second != 0)
        {
            return i.first;
        }
    }
    return 1;
}

//何となくDPで解けばいいのは分かったけど。。
//calcdp(M)を求めるためには、
//calcdp(M/2)~calcdp(M-1)*未使用最小素因数
//の最小値を求める必要がある。
//最小素因数を求める関数はint checkmin(int num)で記載する。
int calcdp(int M)
{
    if (calcmem[M] != 0) return calcmem[M];
    if (M == 1)
    {
        return 1;
    }
    int minval = INF;
    for (int i = M - 1; i >= (M + 1) / 2; i--)
    {
        int tmp = calcdp(i);
        if (tmp >= M)
        {
            calcmem[M] = tmp;
            return tmp;
        }
        else
        {
            int minamp = checkmin(tmp);
            tmp *= minamp;
            minval = min(minval, tmp);
        }
    }
    printf("M %d %d\n", M, minval);
    calcmem[M] = minval;
    return minval;
}

int main()
{
    int N, M;

    cin >> N >> M;

    int amari = M;
    for (int i = 2; i * i < amari; i++)
    {
        int cnt = 1;
        if (amari % i == 0)
        {
            while (amari % i == 0)
            {
                amari /= i;
                cnt *= i;
            }
            calcmem[i] = i;
            soinsu.push_back(P(i, cnt));
            printf("i^n :%d %d\n", i, cnt);
        }
    }
    soinsu.push_back(P(amari,amari));
    printf("i^n :%d %d\n", amari, amari);
    int ans = calcdp(M);
    cout << ans << endl;
}