#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>> a;
    rep(i, n){ int tmp; cin >> tmp; a.push(tmp);}

    rep(i, m){
        int price = a.top();
        a.pop();


        price /= 2;
        a.push(price);
    }
    ll sum = 0;
    while(!a.empty()) {
        sum += a.top();
        a.pop();
    }
    cout << sum << endl;
}

