#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main()
{
    int n;
    cin >> n;

    int ret = 0;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if (n == i * j){
                ret = 1;
            }
        }
        
    }
    
    cout << ((ret == 1) ? "Yes": "No") << endl;
    
}

