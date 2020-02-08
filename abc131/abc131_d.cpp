#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;

bool cmp(const P &a, const P &b){
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<P> a;
    rep(i, n){ int tmp1, tmp2; cin >> tmp1 >> tmp2; a.push_back(P(tmp1, tmp2));}
    sort(a.begin(), a.end(), cmp);

    int tm = 0;
    bool ans = true;
    rep(i, n){
        tm += a[i].first;
        if (tm > a[i].second){
            ans = false;
            break;
        }
    }
    if (ans){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

