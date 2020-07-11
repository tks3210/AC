#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];

    vector<int> ans(4);
    rep(i, n){
        string t = s[i];
        if (t == "AC"){
            ans[0]++;
        } else if (t == "WA") {
            ans[1]++;
        } else if (t == "TLE") {
            ans[2]++;
        } else {
            ans[3]++;
        }
    }

    printf("AC x %d\n", ans[0]);
    printf("WA x %d\n", ans[1]);
    printf("TLE x %d\n", ans[2]);
    printf("RE x %d\n", ans[3]);

}

