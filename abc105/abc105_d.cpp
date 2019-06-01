#include <bits/stdc++.h>    

using namespace std;
typedef long long ll; 


int main(){
    //int num_mod[1000000000] = {0}; //この配列作れなかった。そりゃそうだ
    map<int, int> num_mod;
    int n, m;
    cin >> n >> m;
    vector<int> sum;
    ll sum_mod = 0;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        sum_mod += tmp;
        sum_mod %= m;
        sum.push_back(sum_mod);
        num_mod[(int)sum_mod]++;
    }

    ll ans = 0;
    ans += num_mod[0];
    for(int i = 0; i < n; i++)
    {
        num_mod[sum[i]]--;
        ans += num_mod[sum[i]];
    }
       

    cout << ans << endl;

}