#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, l, t;
    vector<pair<int, int> > ant;
    vector<int> pos;
    cin >> n >> l >> t;
    int pm_sum = 0;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ant.push_back(make_pair(x, y));
        if (y == 1){
            x += t;
            x %= l;
            pm_sum++;
        }else{
            x -= t;
            x = (x < 0) ? x + l: x;
            pm_sum--;
        }
        pos.push_back(x);
    }
    sort(pos.begin(), pos.end());
    // for(auto i:pos)
    // {
    //     cout << i << endl;
    // }

}

