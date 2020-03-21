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


bool ab[100000]={0};
bool ac[100000]={0};
bool bc[100000]={0};

bool isMatch(const char a, const char b){
    return ((a==b)||(a=='?')||(b=='?'));
}

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    int sa, sb, sc;
    sa = (int)a.size();
    sb = (int)b.size();
    sc = (int)c.size();

    rep(i, sa)rep(j, sb) if(!isMatch(a[i],b[j])) ab[50000+i-j]=true;
    rep(i, sa)rep(j, sc) if(!isMatch(a[i],c[j])) ac[50000+i-j]=true;
    rep(i, sb)rep(j, sc) if(!isMatch(b[i],c[j])) bc[50000+i-j]=true;

    int M = 2000;
    int ans = 3*M;
    for(int i=-2*M; i<=2*M;i++) for(int j=-2*M; j<=2*M;j++){
        if(!ab[50000+i] && !ac[50000+j] && !bc[j-i+50000]){
            int L = min(0, min(i,j));
            int R = max(sa, max(i+sb,j+sc));
            ans = min(ans, R-L);
        }
    }
    cout << ans << endl;
}

