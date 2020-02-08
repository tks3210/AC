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
    string s;
    cin >> s;

    bool ans = true;
    rep(i, 3){
        if (s[i] == s[i+1]){
            ans = false;            
        }
    }
    if (ans){
        cout << "Good" << endl;
    } else {
        cout << "Bad" << endl;
    }
}

