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
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}

int main()
{
    string n;
    cin >> n;
    int keta = n.size();
    vector<int> num(n.size(), 0);
    rep(i, n.size()){
        num[i] = n[i]-'0'; 
    }

    //show(num);

    ll sum = 0;
    rep(i, num.size()) sum += num[i];
    int kesu = sum%3;

    if (kesu == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> num_sum(keta+1, 0);
    rep(i, keta) num_sum[i+1] = num_sum[i] + num[i];

    rep1(i, keta){
        if (i == keta) {
            cout << -1 << endl;
            return 0;
        }
        for (int j = 0; j + i <= keta; j++)
        {
            if ((num_sum[j+i]-num_sum[j])%3 == kesu){
                //cout << i << i+j << endl;
                cout << i << endl;
                return 0;
            }
        }
    }

}

