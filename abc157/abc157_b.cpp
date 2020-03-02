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
    int a[3][3] = {0};

    rep(i, 3)rep(j, 3) cin >> a[i][j];

    int n;
    cin >> n;
    vector<int> b(n);
    rep(i, n) {
        cin >> b[i];
    }
    bool bin[3][3] = {0};
    rep(k, n){
        rep(i, 3)rep(j, 3){
            if (b[k] == a[i][j]) bin[i][j] = true;
        }
    }

    // rep(i, 3){
    //     rep(j, 3) cout << bin[i][j];
    //     cout << endl;
    // }
    bool ans = false;
    rep(i, 3){
        if (bin[i][0] && bin[i][1] && bin[i][2]) ans = true; 
    }
    rep(i, 3){
        if (bin[0][i] && bin[1][i] && bin[2][i]) ans = true;
    }
    if(bin[0][0] && bin[1][1] && bin[2][2]) ans =true;
    if(bin[2][0] && bin[1][1] && bin[0][2]) ans =true;

    if(ans)  puts("Yes");
    else puts("No");

}

