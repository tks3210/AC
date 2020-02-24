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
    int n;
    cin >> n;
    vector<P> l;
    rep(i, n){ int tmpx, tmpy; cin >> tmpx >> tmpy; l.emplace_back(tmpx, tmpy);}


    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double dx = l[i].first - l[j].first;
            double dy = l[i].second - l[j].second;
            ans += sqrt((dx * dx) + (dy * dy));
        }        
    }
    double mut = 1;
    rep(i, n-1){
        mut *= (i + 1);
    }
    ans *= (2.0 / (double)n);
    
    printf("%4.10lf", ans);
}

