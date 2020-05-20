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

const int max_n = 200050;
int buka[max_n] = {0};

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    rep(i, n-1){ int tmp; cin >> tmp; buka[--tmp]++;}

    rep(i, n){
        cout << buka[i] << endl;
    }
}

