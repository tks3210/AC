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
const long long INF = 1LL<<60;

const int n_max = 5050;

vector<ll> p(n_max, 0);
vector<ll> c(n_max, 0);


vector<bool> visited(n_max, false);
void dfs(int i, vector<ll>& l){
    visited[i] = true;
    l.push_back(c[i]);
    if (visited[p[i]] != true){
        dfs(p[i], l);
    } else {
        return;
    }
}

int main()
{
    int N, K;
    cin >> N >> K;
    rep(i, N) {
        int tmp; cin >> tmp;
        tmp--;
        p[i] = tmp;
    }
    rep(i, N) cin >> c[i];

    vector<vector<ll>> L;
    rep(i, N){
        vector<ll> l;
        if (visited[i] != true){
            dfs(i, l);
            L.push_back(l);
        }
    }

    ll tans = -MOD;
    rep(i, L.size()){
        ll M = L[i].size();
        ll oneloop_sum = 0;
        rep(j, M) oneloop_sum += L[i][j];
        vector<ll> sum(M*2+1, 0);
        sum[0] = 0;
        rep(j, M*2){
            sum[j+1] = sum[j] + L[i][j%M];
        }
        //show(sum);

        vector<ll> amari(M, -INF);
        amari[0] = 0;

        for (int r = 0; r < M; r++)
        {
            for (int p = 0; p <= M; p++)
            {
                amari[r] = max(amari[r], sum[p+r]-sum[p]);
            }
        }

        int loop = K/M;
        int loopmod = K%M;

        ll ans = -MOD;

        for (int r = 0; r < M;  r++)
        {
            if (r > K) continue;
            ll q = (K-r)/M;
            //if (r == 0 && q == 0) continue;
            if (oneloop_sum > 0) ans = max(ans, amari[r] + oneloop_sum*q);
            else if (r > 0) ans = max(ans, amari[r]);
        }
    
        tans = max(tans, ans);
    }

    cout << tans << endl;
}

