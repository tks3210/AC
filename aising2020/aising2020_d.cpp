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

int mod_calc(int x, int y){
    if (y == 0) return 0;
    return x%y;
}

int main()
{
    int n; string s;
    cin >> n >> s;

    int cnt = 0;
    vector<int> sn(n); 
    rep(i, n) {
        if (s[i] == '1') cnt++;
        sn[i] = s[i] - '0';
    }

    vector<int> mod_first_minus(n), mod_first_plus(n); //0(minus), 1(plus)

    mod_first_minus[0] = mod_calc(1, cnt-1);
    mod_first_plus[0] = mod_calc(1, cnt+1);

    for (int i = 1; i < n; i++)
    {
        mod_first_minus[i] = mod_calc(mod_first_minus[i-1]*2, cnt-1);
        mod_first_plus[i] = mod_calc(mod_first_plus[i-1]*2, cnt+1);
    }

    int smod_plus = 0;
    int smod_minus = 0;
    rep(i, n){
        if (sn[i]){
            smod_plus += mod_first_plus[n-1-i]; smod_plus = mod_calc(smod_plus, cnt+1);
            smod_minus += mod_first_minus[n-1-i]; smod_minus = mod_calc(smod_minus, cnt-1);
        }
    }

    rep(i, n){
        int ans = 1;
        int second; 
        if (sn[i] == 0){
            //plus
            second = smod_plus + mod_first_plus[n-1-i]; second = mod_calc(second, cnt+1);
        } else {
            //minus
            second = smod_minus - mod_first_minus[n-1-i] + cnt-1; second = mod_calc(second, cnt-1);
            if (cnt-1 == 0) ans = 0;
        }

        while(second != 0){
            int bit = __builtin_popcountll(second);
            if (bit == 0) break;
            second %= bit;
            ans++;
        }
        cout << ans << endl;
    }

    

}

