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

bool isfox(string s){
    if (s.size() < 3) return false;
    if (s[0] == 'f' && s[1] == 'o' && s[2] == 'x'){
        return true;
    } else {
        return false;        
    }
}

int main()
{
    int N;
    string s;
    cin >> N >> s;

    s = "V" + s + "V";
    int itr = 0;
    while(itr < s.size()){
        string st = s.substr(itr, 3);
        if (isfox(st)){
            st = s.substr(0, itr) + s.substr(itr+3);
            itr = max(itr-3, 0);
            s = st; 
        } 
        //cout << s << endl;
        itr++;
    }

    cout << s.size() - 2 << endl;


}

