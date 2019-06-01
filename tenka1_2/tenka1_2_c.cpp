#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int sharp[1000000] = {0};
int dot[1000000] = {0};
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    int sums = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '#'){
            sums++;
        }
        sharp[i] = sums;
    }    
    int sumd = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] == '.'){
            sumd++;
        }
        dot[i] = sumd;
    }

    int ans = 10000000;
    for(int i = 0; i < n -1; i++)
    {
        int tmp = sharp[i] + dot[i + 1];
        //printf("%d %d %d %d\n", i, sharp[i], dot[i], sharp[i] + dot[i + 1]);
        ans = min(ans, tmp);
    }
    ans = min(ans, dot[0]);
    ans = min(ans, sharp[n - 1]);
    cout << ans << endl;
 
}

