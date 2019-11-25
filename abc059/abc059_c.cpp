#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int n;

ll func(vector<ll> a, int fugo)
{
    ll ans = 0;
    ll offset = 0; //蓄積する修正量
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == fugo){
            if (a[i] <= offset){
                ans += offset - (a[i] - 1);
                offset = a[i] - 1; 
            }
        } else {
            if (a[i] >= offset){
                ans += (a[i] + 1) - offset;
                offset = a[i] + 1;
            }
        }
        //printf("[%d]", offset);
    }
    //printf("%d ",ans);
    return ans;
}


int main()
{
    cin >> n;
    vector<ll> a;

    ll sum_tmp = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp; cin >> tmp;
        sum_tmp += tmp;
        a.push_back(sum_tmp);
    }
    ll ans = min(func(a, 0), func(a, 1));
    
    cout << ans << endl;

}

