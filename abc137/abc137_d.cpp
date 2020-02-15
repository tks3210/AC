#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> ab;
    rep(i, n){ int tmpa, tmpb; cin >> tmpa >> tmpb; ab.push_back(P(m-tmpa, tmpb));}

    
    priority_queue<int, vector<int>, less<int>> que_gre[m];
    rep(i, n) {
        if (ab[i].first >= 0) que_gre[ab[i].first].push(ab[i].second);
    }

    ll ans = 0;
    priority_queue<int, vector<int>, less<int>> work;
    for (int i = m-1; i >= 0; i--)
    {
        while(!que_gre[i].empty()){
            work.push(que_gre[i].top());
            que_gre[i].pop();
        }
        if(!work.empty()){
            ans += work.top();
            work.pop();
        }
    }
    cout << ans << endl;

}

