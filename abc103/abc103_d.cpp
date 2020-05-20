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

bool cmp(const P &a, const P &b){
    if (a.second == b.second){
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<P> war(m);
    rep(i, m){ cin >> war[i].first >> war[i].second;}

    sort(war.begin(), war.end(), cmp);

    // rep(i, m){
    //     cout << war[i].first << ":" << war[i].second << endl;
    // }
    

    int point = 0;
    int ans = 0;
    rep(i, m){
        if (war[i].first >= point){
            point = war[i].second;
            ans++;
        }
    }

    cout << ans << endl;
}

