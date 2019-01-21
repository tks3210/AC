#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define DOT 0
#define SHARP 1
#define NONE 2
int trout[400][400];
int mv[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
unsigned long long cntdot = 0;
unsigned long long cntsharp = 0;

void countroute(int h, int w, int hmax, int wmax, int targetcolor)
{
    int targ = targetcolor;

    //上下左右に進んで、
    for (int i = 0; i < 4; i++)
    {
        int hnow = h + mv[i][0];
        int wnow = w + mv[i][1];

        //別の色であること、エリア内であること、
        if (0 <= hnow && hnow < hmax && 0 <= wnow && wnow < wmax && trout[hnow][wnow] != NONE)
        {

            if (trout[hnow][wnow] == targ)
            {
                //printf("hnow%d,wnow%d, color%d",hnow,wnow,trout[hnow][wnow]);
                if (trout[hnow][wnow] == DOT)
                {
                    targetcolor = SHARP;
                    cntdot++;
                }else {
                    targetcolor = DOT;
                    cntsharp++;
                }
                trout[hnow][wnow] = NONE;
                countroute(hnow, wnow, hmax, wmax, targetcolor);
            }
        }
    }
}

int main()
{

    int H, W;
    cin >> H >> W;

    for (int i = 0; i < H; i++)
    {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < W; j++)
        {
            if (tmp[j] == '.')
            {
                trout[i][j] = DOT;
            }
            else
            {
                trout[i][j] = SHARP;
            }
        }
    }

    unsigned long long sum = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if(trout[i][j] != NONE){
            int targcolor;
            if (trout[i][j] == DOT){
                cntdot++;
                targcolor = SHARP;
            }else{
                cntsharp++;
                targcolor = DOT;
            }
            trout[i][j] = NONE;
            countroute(i, j, H, W, targcolor);
            sum += cntdot * cntsharp;
            cntdot = 0;
            cntsharp = 0;
            }
        }
    }

    cout << sum << endl;
}