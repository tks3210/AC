#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
 
int like_cnt[31] = {0};




int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            like_cnt[x]++;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < 31; i++)
    {
        if(like_cnt[i] == n){
            ans++;
        }
    }
    cout << ans << endl;

}