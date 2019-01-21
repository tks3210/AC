#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#define min(x, y) (x > y ? y : x)
#define LIMITED 1000000007
using namespace std;

/* 
W = 1
 pat = 1 (0)
W = 2
 pat = 2 (1)
W = 3
 pat = 3 (1)
W = 4
 pat = 5 (2,1)
W = 5
 pat = 8 (3,2)
W = 6
 pat = 13 (5,3,4)
W = 7
 pat = 21 (8,5,6)  
W = 8
 pat = 34 (13,8,10,9)
*/
int sum[9] = {0, 1, 2, 3, 5, 8, 13, 21, 34};
int pat[9][7] = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 2, 0, 0, 0, 0},
    {3, 2, 2, 3, 0, 0, 0},
    {5, 3, 4, 3, 5, 0, 0},
    {8, 5, 6, 6, 5, 8, 0},
    {13, 8, 10, 9, 10, 8, 13},
};

long long anstable[100][8] = {0};

void calc_dp(int H, int W)
{
    anstable[0][0] = 1;
    for (int i = 1; i <= H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (j != 0)
            {
                anstable[i][j] = anstable[i - 1][j - 1] * pat[W][j - 1] + anstable[i-1][j] * (sum[W] - pat[W][j] - pat[W][j-1]) + anstable[i-1][j+1] * pat[W][j];
            }
            else
            {
                anstable[i][j] = anstable[i-1][j] * (sum[W] - pat[W][j]) + anstable[i-1][j+1] * pat[W][j];
            }
            anstable[i][j] %= LIMITED;
            //printf("i%d j%d :%d\n",i,j,anstable[i][j]);
        }
    }
}

int main()
{
    int H, W, K;
    cin >> H >> W >> K;

    calc_dp(H, W);

    cout << anstable[H][K-1] << endl;
}