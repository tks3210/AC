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
    int n; string s;
    cin >> n >> s;
    
    
    vector<int> is(n);    
    rep(i, n){
        if (s[i] == 'R') is[i] = 0;
        else if (s[i] == 'G') is[i] = 1;
        else is[i] = 2;
    }

    ll ans = 0;
    rep1(j, n-2){
        //真ん中の数字をjとする。

        int l[2] = {0};
        for(int i = j-1; i>=0; i--){
            if (is[i] == is[j]) continue;
            if ((is[i]+1)%3 == is[j]) l[0]++;
            else l[1]++; 
        }
        int r[2] = {0};
        for(int i = j+1; i<n; i++){
            if (is[i] == is[j]) continue;
            if ((is[i]+1)%3 == is[j]) r[0]++;
            else r[1]++; 
        }

        int com = 0;
        for(int move = 1; move<=min(j,(n-1)-j); move++){
            if (is[j+move] != is[j] && is[j-move] != is[j] && is[j+move] != is[j-move]){
                com++;
            }
        }
        int tans = (l[0]*r[1]) + (l[1]*r[0]) - com;
        //cout << com << ":" << tans << endl;
        ans += tans;
    }

    cout << ans << endl;
}

