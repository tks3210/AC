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


#define N_MAX 100050
int ans_num[N_MAX] = {0};

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    rep(i, q){ int tmp; cin >> tmp; ans_num[--tmp]++;}

    rep(i, n){
        if (k - q + ans_num[i] > 0) puts("Yes");
        else puts("No");
    }

}

