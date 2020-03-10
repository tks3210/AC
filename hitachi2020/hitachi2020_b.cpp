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
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A);
    vector<int> b(B);
    int minA = MOD, minB = MOD;
    rep(i, A) { cin >> a[i]; minA = min(minA, a[i]);}
    rep(i, B) { cin >> b[i]; minB = min(minB, b[i]);}

    int ans = minA + minB;

    rep(i, M){
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        ans = min(ans, a[x] + b[y] - c);
    }

    cout << ans << endl;




}

