#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;

#define LARGE 1000000007
int cnt[30] = {0};

int main (){
    int n;
    string s;
    cin >> n;
    cin >> s;

    for(int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']++;
    }
    ll ans = 1;
    for(int i = 0; i < 30; i++)
    {
        ans = (ans * (cnt[i] + 1)) % LARGE;
    }
    cout << ans - 1<< endl; 
}