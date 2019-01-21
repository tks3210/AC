
//absのdefineは怖いのでおとなしくstdlib使う
//0の隣接点は必ずしも0じゃないよ！！
//情報の中に、0点じゃないものが存在する⇒それを基準に他の情報と比較する。
#include <iostream>
#include <stdlib.h>
using namespace std;

#define NUMARRAY 101
#define INFONUM 100
long map[NUMARRAY][NUMARRAY] = {0};
int kouho[NUMARRAY][NUMARRAY] = {0};
struct ten
{
    int x;
    int y;
    long h;
};

struct ten info[INFONUM] = {0};

void mapping(struct ten nonzero)
{

    for (int i = 0; i < NUMARRAY; i++)
    {
        for (int j = 0; j < NUMARRAY; j++)
        {
            int base_norm = abs(i - nonzero.x) + abs(j - nonzero.y);
            map[i][j] = base_norm + nonzero.h;
        }
    }
}

struct ten info_map(int infonum)
{
    struct ten ans;
    for (int i = 0; i < NUMARRAY; i++)
    {
        for (int j = 0; j < NUMARRAY; j++)
        {
            int NGflag = 0;
            for (int k = 0; k < infonum; k++)
            {
                int base_norm = abs(i - info[k].x) + abs(j - info[k].y);
                if (info[k].h == 0)
                {
                    if (map[i][j] > (base_norm + info[k].h)) NGflag = 1;
                }
                else
                {
                    if (map[i][j] != (base_norm + info[k].h)) NGflag = 1;
                }
            }
            if (NGflag == 0){
                ans.x = i;
                ans.y = j;
                ans.h = map[i][j];
            }
        }
    }
    return ans;
}

int main()
{
    int N;
    cin >> N;
    int flag;
    for (int i = 0; i < N; i++)
    {
        int x, y, h;
        cin >> x >> y >> h;
        if (h != 0)
            flag = i;
        info[i].x = x;
        info[i].y = y;
        info[i].h = h;
    }

    mapping(info[flag]);
    struct ten ans = info_map(N);
    
    cout << ans.x << " " << ans.y << " " << ans.h << endl;
}