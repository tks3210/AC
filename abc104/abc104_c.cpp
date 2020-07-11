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


int main()
{
    int D, G;
    cin >> D >> G;
    vector<P> pc(D);
    rep(i, D){ cin >> pc[i].first >> pc[i].second;}

    int ans = 1e9;
    rep(i, (1<<D)){
        int tans = 0;
        int remain = G;
        for (int j = D-1; j >= 0; j--)
        {
            int ten = j*100 + 100;
            if ((i>>j)&1){
                if (remain <= pc[j].first*ten) {
                    tans += (remain + (ten) -1)/ (ten);
                    remain = 0; 
                } else {
                    tans += pc[j].first;
                    remain -= pc[j].first*ten + pc[j].second;
                }
                if (remain <= 0) break;
            }
        }
        if (remain > 0) continue;
        //cout << tans << endl;
        ans = min(ans, tans);
    }
    cout << ans << endl;
}

