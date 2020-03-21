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
    int n;
    cin >> n;
    vector<int> c;
    rep(i, n){ int tmp; cin >> tmp; c.push_back(tmp);}

    vector<int>  div_num(n);
    rep(i, n){
        rep(j, n){
            if((c[j]%c[i])==0 && i!=j){
                div_num[j]++;
            }
        }
    }

    double ans = 0;
    rep(i, n){
        double e = (double)(div_num[i]/2+1)/(double)(div_num[i]+1);
        // 0:1/1 1:1/2 2:2/3 3:2/4 4:3/5
        //cout << e << endl;
        ans += e;
    }
    printf("%.10lf\n",ans);
}

