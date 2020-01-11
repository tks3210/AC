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
    vector<pair<string, int>> a;

    rep(i ,n){
        string s;
        int num;
        cin >> s >> num;
        a.push_back(make_pair(s, num));
    }

    string x;
    cin >> x;
    int flag = 0;
    int ans = 0;
    rep(i, n){
        if(flag) ans += a[i].second;
        if (a[i].first == x){
            flag = 1;
        }
    }

    cout << ans << endl;
}

