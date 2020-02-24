#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(ll x, ll y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


template<class X> void factorization(X input, set<X>& Pnumber){
    for(X i = 2; i*i <= input; i++)
    {
        if (input % i == 0){
            while (input % i == 0){
                input /= i;
                Pnumber.insert(i);
            }
        }
    }
    if (input != 1) Pnumber.insert(input);
}

int main()
{
    ll a, b;
    cin >> a >> b;
    ll num = gcd(a, b);

    set<ll> pnum;
    factorization(num, pnum);

    cout << pnum.size() + 1 << endl;
}

