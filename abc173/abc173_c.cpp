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


int cmap[10][10] = {0};

int main()
{
    int h, w, k;
    cin >> h >> w >> k;

    rep(i, h){
        string t; cin >> t;
        rep(j, w){
            if (t[j] == '#') cmap[i][j] = 1;
        }
    }

    // rep(i, h){
    //     rep(j, w){
    //         cout<< cmap[i][j];
    //     }
    //     cout << endl;
    // }

    int bit = h+w;
    //2^12
    int ans = 0;
    rep(i, (1<<bit)){
        set<int> hr, wr;
        for (int j = 0; j < bit; j++)
        {
            if ((i>>j)&1){
                if (j < h){
                    hr.insert(j);
                } else {
                    wr.insert(j-h);
                }
            }
        }
        int tmp = 0;
        rep(ih, h)rep(iw, w){
            if (cmap[ih][iw] == 1){
                if (hr.find(ih) == hr.end() && wr.find(iw) == wr.end()){
                    //cout << ih << iw << endl;
                    tmp++;                    
                }
            }
        }
        if (tmp == k) {
           // cout << i << endl;
            ans++;
        }
    }

    cout << ans << endl;


}

