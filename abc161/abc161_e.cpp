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
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    vector<int> b_f(n, 0);
    vector<int> b_b(n, 0);

    int k_t = 0;
    rep(i, n){
        if (s[i] == 'o'){
            k_t++;
            b_f[i] = k_t;
            i+=c;
        } 
        if (k_t >= k || i >= n){
            break;
        }
    }
    k_t = k;
    for (int i = n-1; i >= 0; i--)
    {
        if (s[i] == 'o'){
            b_b[i] = k_t;
            i-=c;
            k_t--;
        }
        if (k_t <= 0 || i < 0){
            break;
        }
    }
    
    // show(b_f);
    // show(b_b);

    rep(i, n){
        if (b_f[i] == b_b[i] && b_f[i] != 0){
            cout << i+1 << endl;
        }
    }
    
}

