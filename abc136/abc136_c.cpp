#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    vector<int> h;
    rep(i, n){ int tmp; cin >> tmp; h.push_back(tmp);}

    int ans = 0;
    h[0]--;
    for (int i = 1; i < n; i++)
    {
        if(h[i] < h[i-1]){
            ans = 1;
            break;
        } else if (h[i] > h[i - 1]){
            h[i]--;
        }
    }
    cout << ((ans == 0)? "Yes": "No")<< endl;
}

