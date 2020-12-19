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

/*
1 ~ N-1 の約数の合計
*/



int main()
{
    int n;
    cin >> n;
    // int ans = 0; 
    // rep1(i, n-1){
    //     set<int> a;
    //     divisor(i, a);
    //     ans += a.size();
    // }
    int ans = 0;
    for (int a = 1; a < n; a++)
    {
        for (int b = 1; a*b < n ; b++)
        {
            ans++;        
        }
    }
    
    cout << ans << endl;
}

