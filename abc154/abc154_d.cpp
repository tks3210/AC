#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p;
    rep(i, n){ int tmp; cin >> tmp; p.push_back(tmp);}

    vector<int> sum;
    int tmpsum = 0;
    rep(i, n) { sum.push_back(tmpsum); tmpsum += p[i];}
    sum.push_back(tmpsum);

    int ans = 0;
    rep(i, n-k+1){
        ans = max(ans, sum[i+k] - sum[i]);
    }

    printf("%lf\n",(double)(ans + k) / 2.0);

}

