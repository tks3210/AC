//[1015]RE(実行時エラー)はSEGVを疑う

#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define abs(x) (x > 0 ? x : -x)
#define max(x, y) (x > y ? x : y)
typedef pair<int, int> P;
vector<P> pnt;
long IntPow(int a, int n)
{
    int num = 1;
    for (int i = 0; i < n; i++)
    {
        num *= a;
    }
    return num;
}

int main()
{
    int N;
    int oddflag = -1;
    int NGflag = 0;
    long maxnorm = 0;
    char ARM[1001][41] = {0};
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        int norm = abs(tmp1) + abs(tmp2);
        if (oddflag == -1)
        {
            oddflag = norm % 2;
            maxnorm = norm;
        }
        else
        {
            maxnorm = max(maxnorm, norm);
            if (norm % 2 != oddflag)
            {
                NGflag = 1;
            }
        }

        pnt.push_back(P(tmp1, tmp2));
    }

    //NG/OKの判定
    if (NGflag == 0)
    {
        int armnum = 1;
        int lastarm = 0;

        //armの数確定
        maxnorm >>= 1;
        while (maxnorm != 0)
        {
            armnum++;
            maxnorm >>= 1;
        }

        //補正用armの有無

        if (!oddflag)
            lastarm++;

        //armの向き確定
        for (int i = 0; i < pnt.size(); i++)
        {
            for (int j = armnum - 1; j >= 0; j--)
            {
                long u = pnt[i].first + pnt[i].second;
                long v = pnt[i].second - pnt[i].first;
                if (u >= 0 && v >= 0)
                {
                    //up
                    pnt[i].second -= IntPow(2, j);
                    ARM[i][j] = 'U';
                }
                else if (u >= 0 && v < 0)
                {
                    //right
                    pnt[i].first -= IntPow(2, j);
                    ARM[i][j] = 'R';
                }
                else if (u < 0 && v >= 0)
                {
                    //left
                    pnt[i].first += IntPow(2, j);
                    ARM[i][j] = 'L';
                }
                else if (u < 0 && v < 0)
                {
                    //down
                    pnt[i].second += IntPow(2, j);
                    ARM[i][j] = 'D';
                }
            }
            //oddflagが0なら補正
            if (lastarm)
            {
                if (pnt[i].first == 0 && pnt[i].second == 1)
                {
                    ARM[i][armnum] = 'U';
                }
                else if (pnt[i].first == 1 && pnt[i].second == 0)
                {
                    ARM[i][armnum] = 'R';
                }
                else if (pnt[i].first == -1 && pnt[i].second == 0)
                {
                    ARM[i][armnum] = 'L';
                }
                else if (pnt[i].first == 0 && pnt[i].second == -1)
                {
                    ARM[i][armnum] = 'D';
                }
                else
                {
                    printf("value error");
                }
            }
        }
        //output
        cout << armnum + lastarm << endl;

        cout << "1";
        for (int i = 1; i < armnum; i++)
        {
            cout << " " << IntPow(2, i);
        }
        if (lastarm) cout << " " <<"1";

        cout << endl;
        for (int i = 0; i < pnt.size(); i++)
        {
            for (int j = 0; j < armnum + lastarm; j++)
            {
                cout << ARM[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        printf("-1\n");
    }
}
