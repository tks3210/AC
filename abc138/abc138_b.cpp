#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}

    double ans_div = 0;
    rep(i, n){
        ans_div += (double)1.0 / a[i];
    }
    printf("%.15f\n", (double)1/ans_div);
}

