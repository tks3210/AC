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
    string s;
    int q;
    cin >> s >> q;

    int rev = 0;

    vector<char> first;
    vector<char> last;
    rep(i, q){
        int t; cin >> t;
        if (t == 1){
            rev ^= 1;
        } else {
            int f;
            char c;
            cin >> f >> c;
            if (f == 1){
                if (rev) last.push_back(c);
                else first.push_back(c);
            } else {
                if (!rev) last.push_back(c);
                else first.push_back(c);
            }
        }
    }

    if (!rev){
        rep(i, first.size()) cout << first[first.size()-1-i];
        cout << s;
        rep(i, last.size()) cout << last[i];        
    } else {
        rep(i, last.size()) cout << last[last.size()-1-i];
        reverse(s.begin(), s.end());
        cout << s;
        rep(i, first.size()) cout << first[i];        
    }
    cout << endl;

}

