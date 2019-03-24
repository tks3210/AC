#include <bits/stdc++.h>    

using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;

    int ans_tmp = 0;
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'){
            ans_tmp++;
        } else {
            ans_tmp = 0;
        }
        ans = max(ans, ans_tmp);
    }
    cout << ans << endl;
}