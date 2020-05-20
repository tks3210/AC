#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define PI 3.14159265359
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
    double a, b, h, m;
    cin >> a >> b >> h >> m;

    double larg = 6*m; 
    double sarg = 30*h + 0.5*m;

    double diff = abs(larg-sarg);

    double ans = pow(a, 2) + pow(b, 2) - (2*a*b)*cos(diff*PI/180);

//    cout << sqrt(ans) << endl;

    printf("%10.11f", sqrt(ans));
}

