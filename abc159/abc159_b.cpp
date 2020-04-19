#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    string s;
    
    cin >> s;
    int n = s.size();
    string fs = s.substr(0, (n-1)/2);
    string ls = s.substr((n-1)/2+1, (n-1)/2);
    string rs = s;
    string rfs = fs;
    string rls = ls;
    reverse(rs.begin(), rs.end());
    reverse(rfs.begin(), rfs.end());
    reverse(rls.begin(), rls.end());

    
    bool ans = true;
    if (ls != rls) ans = false;
    if (fs != rfs) ans = false;
    if (s != rs) ans = false;
    
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

