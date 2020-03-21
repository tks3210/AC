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


vector<string> sall;

void dfs(string s, int n, char c_max){
    if (n == -1) return;

    for (char c = 'a'; c <= c_max; c++){
        dfs(s+c, n-1, c_max);
    }
    char n_c = c_max+1;
    dfs(s+n_c, n-1, n_c);

    if (n==0) sall.push_back(s);
    return;
}

int main()
{
    int n;
    cin >> n;

    string s = "a";
    dfs(s, n-1, 'a');

    rep(i, sall.size()){
        cout << sall[i] << endl;
    }

}

