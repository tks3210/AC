#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main()
{
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    char tmp = s[0];
    int change = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i - 1]){
            change++;
        }
    }
    change -= k*2;
    if(change < 0) change = 0;
    cout << (n - change - 1) << endl;
}

