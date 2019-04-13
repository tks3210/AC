#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    vector<int> hito_num;
    vector<int> hito_sum;

    int before_style = s[0]; 
    int tmp_num = 1;
    int tmp_sum = 1;
    hito_num.push_back(0);
    hito_sum.push_back(0);

    for(int i = 1; i < n; i++)
    {
        if (s[i] != before_style){
            if(before_style == '1'){
                hito_num.push_back(tmp_num);
                hito_sum.push_back(tmp_sum);
            }
            before_style = s[i];
            tmp_num = 0;
        }
        tmp_num++;
        tmp_sum++;
    }
    hito_sum.push_back(tmp_sum);
    
    // for(int i = 0; i < hito_num.size(); i++)
    // {
    //     cout << hito_num[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < hito_sum.size(); i++)
    // {
    //     cout << hito_sum[i] << " ";
    // }

    int ans = 0;
    if ((k + 1)>= hito_sum.size()) ans = hito_sum[hito_sum.size()-1];     
    for(int i = 0; i + k < hito_sum.size(); i++)
    {
        ans = max(ans, hito_sum[i + k] - hito_sum[i] + hito_num[i]);
    }
    
    cout << ans << endl;

}

