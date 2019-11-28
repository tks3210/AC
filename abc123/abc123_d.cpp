#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int cake_num[3];
    int k;
    vector<vector<ll> >  cake_val(3);
    vector<ll>  cake_sum;
    vector<ll>  cake_ans;
    for(int i = 0; i < 3; i++)
    {
        int num;
        cin >> num;
        cake_num[i] = num;
    }
    cin >> k;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < cake_num[i]; j++)
        {
            ll tmp;
            cin >> tmp;
            cake_val[i].push_back(tmp);
        }
    }

    for(int i = 0; i < cake_num[0]; i++)
    {
        for(int j = 0; j < cake_num[1]; j++)
        {
            ll tmp = cake_val[0][i] + cake_val[1][j];
            cake_sum.push_back(tmp);
        }
    }

    sort(cake_val[2].begin(), cake_val[2].end(), greater<ll>());
    sort(cake_sum.begin(), cake_sum.end(), greater<ll>());
    
    for(int i = 0; i < min(k, (int)cake_sum.size()); i++)
    {
        for(int j = 0; j < min(k, (int)cake_val[2].size()); j++)
        {
            ll tmp = cake_sum[i] + cake_val[2][j];
            cake_ans.push_back(tmp);
        }
    }
    
    sort(cake_ans.begin(), cake_ans.end(), greater<ll>());
    for(int i = 0; i < k; i++)
    {
        cout << cake_ans[i] << endl;
    }

}

