#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

string S;
int gx, gy;

int walk(int W, int X, int Y, int Z)
{
    int posx = 0;
    int posy = 0;
    int ans = 0;
    //printf("%d%d%d%d\n",W,X,Y,Z);
    if (posx == gx && posy == gy)
    {
        ans = 1;
    }
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == 'W')
        {
            posx += W % 3 - 1;
            posy += W / 3 - 1;
        }
        else if (S[i] == 'X')
        {
            posx += X % 3 - 1;
            posy += X / 3 - 1;
        }
        else if (S[i] == 'Y')
        {
            posx += Y % 3 - 1;
            posy += Y / 3 - 1;
        }
        else
        {
            posx += Z % 3 - 1;
            posy += Z / 3 - 1;
        }
        //printf("%d, %d, %d, %d\n", posx, posy, gx, gy);
        if (posx == gx && posy == gy)
        {
            ans = 1;
        }
    }
    return ans;
}

int walk_24pat()
{
    /* 
    Left = 3*1 + 2 = 5
    Right = 3*1 + 0 = 3
    Up = 3*2 + 1 = 7
    Down = 3*0 + 1 = 1
    */
    int ans = 0;
    ans += walk(1, 3, 5, 7);
    ans += walk(1, 3, 7, 5);
    ans += walk(1, 5, 3, 7);
    ans += walk(1, 5, 7, 3);
    ans += walk(1, 7, 3, 5);
    ans += walk(1, 7, 5, 3);

    ans += walk(3, 1, 5, 7);
    ans += walk(3, 1, 7, 5);
    ans += walk(3, 5, 1, 7);
    ans += walk(3, 5, 7, 1);
    ans += walk(3, 7, 1, 5);
    ans += walk(3, 7, 5, 1);

    ans += walk(5, 1, 3, 7);
    ans += walk(5, 1, 7, 3);
    ans += walk(5, 3, 1, 7);
    ans += walk(5, 3, 7, 1);
    ans += walk(5, 7, 1, 3);
    ans += walk(5, 7, 3, 1);

    ans += walk(7, 1, 3, 5);
    ans += walk(7, 1, 5, 3);
    ans += walk(7, 3, 1, 5);
    ans += walk(7, 3, 5, 1);
    ans += walk(7, 5, 1, 3);
    ans += walk(7, 5, 3, 1);

    return ans;
}

int main()
{
    cin >> S;
    cin >> gx >> gy;

    int ans = walk_24pat();
    if (ans != 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}