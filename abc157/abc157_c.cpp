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
    int n, m;
    cin >> n >> m;
    vector<P> sc(m);
    rep(i, m){ cin >> sc[i].first >> sc[i].second;}

    int min_n = 1;
    rep(i, n-1){
        min_n *= 10;
    }
    int max_n =min_n*10;

    int ans = -1;
    bool isbad = false;
    if (min_n == 1) min_n = 0;
    for (min_n; min_n < max_n; min_n++){
        isbad = false;
        rep(i, m){
            int keta = n - sc[i].first + 1;
            if (keta == 1){
                if(min_n%10 != sc[i].second) isbad = true; 
            } else if (keta == 2){
                if((min_n%100)/10 != sc[i].second) isbad = true; 
            } else {
                if(min_n/100 != sc[i].second) isbad = true; 
            }
        }
        if(!isbad) {ans = min_n; break;}
    }

    cout << ans << endl;
}

