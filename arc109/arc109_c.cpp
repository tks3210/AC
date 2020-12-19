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

string janken(string t){
    string ans = "";
    rep(i, t.size()/2){
        int l = i*2;
        int r = i*2+1;
        if ((t[l] == 'R' && t[r] == 'S')||(t[l] == 'S' && t[r] == 'P')||(t[l] == 'P' && t[r] == 'R')){
            //l win
            ans += t[l];
        } else {
            ans += t[r];
        }
    }
    return ans;
}

int main()
{
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    string t = s+s;
    while(k!=0){
        string tmp = janken(t);
        t = tmp + tmp;
        //cout << t << endl;
        k--;
    }
    cout << t[0] << endl;
}

