#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int onecnt[40] = {0};
int zerocnt[40] = {0};
ll allset[40] = {0};
bool kbit[40] = {0};



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

    int kt = k;
    for(int i = 0; kt != 0; i++)
    {
        kbit[i] = (kt % 2 == 1) ? 1 : 0;
        kt >>= 1;
    }
    


    for (int i = 0; i < 40; i++)
    {
        //cout << onecnt[i] << " ";
    }

    for (int i = 0; i < 40; i++)
    {
        allset[i] = (onecnt[i] > zerocnt[i]) ? onecnt[i]: zerocnt[i];
        allset[i] *= (1 << i);
        if(i != 0) allset[i] += allset[i-1];
    }



    for(int i = 39; i >= 0; i--)
    {
        for(int j = 39; j >= 0; j--)
        {
            if(j > i){
                
            }

        }
        
    }
    

}