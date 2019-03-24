#include <bits/stdc++.h>    

using namespace std;

#define NUM_CITY 500

int rootcnt[NUM_CITY + 1][NUM_CITY + 1] = {0};

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 0; i < m; i++)
    {
        int tmpl, tmpr;
        cin >> tmpl >> tmpr;
        for(int j = 1; j <= tmpl; j++)
        {
            rootcnt[j][tmpr]++;
        }
    }
    
    for(int i = 0; i < q; i++)
    {
        int tmpl, tmpr;
        cin >> tmpl >> tmpr;
        int ans = 0;
        for(int j = 1; j <= tmpr; j++)
        {
            ans += rootcnt[tmpl][j];
        }
        cout << ans << endl;        
    }

}