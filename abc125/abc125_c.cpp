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
    int n;
    cin >> n;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}


    vector<int> gcd_len_1(n);
    vector<int> gcd_len_2(n);
    gcd_len_1[0] = a[0]; gcd_len_2[n-1] = a[n-1];

    rep1(i, n-1) gcd_len_1[i] = gcd(a[i], gcd_len_1[i-1]);
    rep1(i, n-1) gcd_len_2[n-1-i] = gcd(a[n-1-i], gcd_len_2[n-i]);

    // show(gcd_len_1);
    // show(gcd_len_2);

    int ans = 0;
    rep(i, n) {
        int tmpgcd;
        if (i == 0) {
            tmpgcd = gcd_len_2[1];
        } else if (i == n-1) {
            tmpgcd = gcd_len_1[n-2];
        } else {
            tmpgcd = gcd(gcd_len_1[i-1], gcd_len_2[i+1]);
        }
        //cout << tmpgcd << endl; 
        ans = max(ans, tmpgcd);
    }
    cout << ans << endl;
}

