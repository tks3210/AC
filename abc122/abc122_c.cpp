#include <bits/stdc++.h>    

using namespace std;
typedef long long ll;

int ac_map[100001] = {0};

int main(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = n; i > 0; i--)
    {
        if (s[i] == 'C' && s[i-1] == 'A'){
            ac_map[i] = ac_map[i+1] + 1;
        } else {
            ac_map[i] = ac_map[i+1];
        }
        
    }

    // for(int i = 0; i <= n; i++)
    // {
    //     printf("%d ", ac_map[i]);
    // }
    
    for(int i = 0; i < q; i++)
    {
        int tmpl, tmpr;
        cin >> tmpl >> tmpr;
        cout << ac_map[tmpl] - ac_map[tmpr] << endl;
    }


}