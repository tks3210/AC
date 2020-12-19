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
template<class T> inline bool chval(T& a, T b) {if (a != b) {a = b; return true;} return false;}

bool next_light(vector<int> &a, vector<int>&a_next){
    int n = a.size();
    vector<int> a_diff(n+1);
    // a      :   0  2  0  1  0  0
    // a_diff :  2 -1  2 -2  1 -1 -1
    // next   :   2  1  3  1  2  1
    rep(i, n){
        int l = max(0, i-a[i]);
        int r = min(n, i+1+a[i]);
        a_diff[l]++;
        a_diff[r]--;
    }

    a_next[0] = a_diff[0];
    for (int i = 1; i < n; i++)
    {
        a_next[i] = a_diff[i] + a_next[i-1];
    }
    rep(i, n){
        if (a[i] != a_next[i]) return false; 
    }
    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}

    rep(i, k){
        vector<int> a_next(n, 0);
        if (next_light(a, a_next)){
            break;
        }
        a = a_next;
    }

    show(a);
}

