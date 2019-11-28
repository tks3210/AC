#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;


int main()
{
    int n;
    cin >> n;  
    string s;
    cin >> s;
    rep(i, s.size()){
        s[i] = s[i] + (char)n;
        if (s[i] > 'Z'){
            s[i] -= 'Z';
            s[i] += 'A' - 1;
        }
    }

    cout << s << endl;

}

