#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int x_point[11][11];


int func(int i , int j, int D){
    int sum = 0;
    for (int d = 0; d < D; d++)
    {   
        sum += (x_point[i][d] - x_point[j][d]) * (x_point[i][d] - x_point[j][d]);
    }
    //printf("%d", sum);
    for (int k = 0; k < 150; k++)
    {
        if (sum == (k*k)){
            return 1;
        }
    }
    return 0;
}

int main()
{
    int D,N;
    cin >> N >> D;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < D; j++)
        {
            int tmp;
            cin >> tmp;
            x_point[i][j] = tmp; 
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            ans += func(i , j, D);
        }        
    }
    
    cout << ans << endl;
}

