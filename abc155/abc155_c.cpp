#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<string, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n;
    cin >> n;
    vector<string> s;
    rep(i, n){ string tmp; cin >> tmp; s.push_back(tmp);}

    //O(nlogn)
    sort(s.begin(), s.end());

    // show(s);
    // cout << endl << endl;
    //O(n)
    int maxcnt = 0;
    int cnt = 1;
    vector<P> ans;
    rep(i, n-1){
        if (s[i] == s[i+1]){
            cnt++;
        } else {
            ans.emplace_back(s[i], cnt);
            cnt = 1;
        }
        maxcnt = max(maxcnt, cnt);
    }
    ans.emplace_back(s[n-1], cnt);

    rep(i, ans.size()){
        if (ans[i].second == maxcnt){
            cout << ans[i].first << endl;
        }
    }

}

