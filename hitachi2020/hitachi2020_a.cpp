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
    string s; cin >> s;

    bool ans = true;
    rep(i, s.size()){
        if (i % 2 == 0){
            if (s[i] != 'h') ans =false;
        } else {
            if (s[i] != 'i') ans =false;
        }
    }
    if (s.size() % 2 == 1) ans = false;
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}

