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
    int n, y;
    cin >> n >> y;
    y /= 1000;

    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; i+j <= n; j++)
        {
            int amari = y-(i*10)-(j*5);
            if (amari == n-i-j){
                cout << i << " " << j << " " << amari << endl;
                return 0;
            }
        }
    }    
    cout << "-1" << " -1" << " -1" <<endl;
}

