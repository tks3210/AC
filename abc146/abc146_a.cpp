#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;


int main()
{
    string s;
    string  day[7] = { "SUN","MON","TUE","WED","THU","FRI","SAT"};


    cin >> s;
    int ans = 0;
    rep(i, 7){
        if (s == day[i]){
            ans = 7 - i;
        }
    }
    cout << ans << endl;
}

