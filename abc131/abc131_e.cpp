#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    int n, k;
    cin >> n >> k;
    int div = (n-1)*(n-2)/2 - k;
    if (div >= 0){
        cout << (n-1) + div << endl;
        rep(i, n-1) cout << "1 " << i+2 << endl;
        for (int i = 2; i <= n; i++)
        {
            for (int j = i+1; j <= n; j++)
            {
                if(div != 0){
                    cout << i << " " << j << endl;
                    div--;
                }
            }            
        }
    } else {
        cout << "-1" << endl;
    }
}

