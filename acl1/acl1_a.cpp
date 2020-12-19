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
#include <atcoder/all>

using namespace atcoder;

int main()
{
    int n;
    cin >> n;
    vector<P> a(n);
    rep(i, n){
        int t1, t2; 
        cin >> t1 >> t2;
        a[i].first = t1; a[i].second = t2;
    }
    vector<P> b = a;
    sort(a.begin(), a.end());

    dsu d(n+1);
    set<int> box;
    rep(i, n){
        //今まで格納した点の内、自分よりyが小さいものとマージする。(y基準でマージする)
        int x = a[i].first;
        int y = a[i].second;
        vector<int> rm;
        for (auto b:box)
        {
            if (b < y) {
                d.merge(b, y);
                rm.push_back(b);
                //printf("%d%d\n", b, y);
            } else {
                break;
            }
        }
        for (int i = 1; i < rm.size(); i++)
        {
            box.erase(rm[i]);
        }
                 
        box.insert(y);
    }

    rep(x, n){
        cout << d.size(b[x].second) << endl;
    }
}


