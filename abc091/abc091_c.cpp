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
    int n;
    cin >> n;
    vector<P> rp(n), bp(n);

    rep(i, n){ cin >> rp[i].first >> rp[i].second;}
    rep(i, n){ cin >> bp[i].first >> bp[i].second;}
    sort(bp.begin(), bp.end());
    sort(rp.begin(), rp.end());

    int ans = 0;
    rep(i, n){
        P p = bp[i];
        P x = {-1, -1};
        int mpoint = -1; 
        rep(j, n){
            if(p.first < rp[j].first && rp[j].first != 1000) {
                break;
            } else {
                if (p.second > rp[j].second){
                    if (x.second < rp[j].second){
                        x = rp[j];
                        mpoint = j;
                    }
                }
            }
        }
        if (mpoint != -1){
            ans++;
            rp[mpoint] = {1000, 1000};            
        }
    }

    cout << ans << endl;

}

