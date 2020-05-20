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

ll calc(int x){
    vector<ll> num(5, 0);
    ll tmp = 1;
    for (int i = 0; i < 5; i++)
    {
        tmp *= x;
        num[i] = tmp;        
    }
    
    ll ans = num[4];
    return ans;
}


int main()
{
    ll x;
    cin >> x;

    //(a+1)^5 - (a)^5

    for (int a = -240; a < 240; a++)
    {
        for (int b = -240; b < 240; b++)
        {
            if (calc(a)-calc(b) == x){
                cout << a << " " << b << endl;
                return 0;
            }
        }
        
    }
    

}

