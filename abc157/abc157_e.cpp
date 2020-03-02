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
    string s;
    cin >> s;
    int q;
    cin >> q;
    set<int> abet[26];
    rep(i, s.size()){
        int num = s[i] - 'a';
        abet[num].insert(i);
    }

    rep(i, q){
        int query;
        cin >> query;
        if (query == 1){
            int p1; char p2;
            cin >> p1 >> p2;
            p1--;
            int num_replace = (int)p2 - 'a';
            int num_old = s[p1] - 'a';
            abet[num_old].erase(p1);
            s[p1] = p2;
            abet[num_replace].insert(p1);

        } else {
            int p1, p2;
            cin >> p1 >> p2;
            p1--; p2--;
            int ans = 0;
            rep(j, 26){
                if(abet[j].lower_bound(p1) != abet[j].upper_bound(p2)){
                    //char c = j + 'a';
                    //cout << "["<< c << "]";
                    ans++;
                }
            }
            // rep(j, 26){
            //     cout << (char)(j + 'a') << ":";
            //     for(auto x:abet[j]){
            //         cout << x << " ";
            //     }
            //     cout << endl;
            // }
            cout << ans << endl;
        }
    }



}

