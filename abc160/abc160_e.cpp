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
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C; 
    vector<ll> p(A);
    vector<ll> q(B);
    vector<ll> r(C);
    rep(i, A) { cin >> p[i]; }
    rep(i, B) { cin >> q[i]; }
    rep(i, C) { cin >> r[i]; }
    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());
    sort(r.begin(), r.end(), greater<ll>());

    vector<ll> pd(p.begin(), p.begin()+X);
    vector<ll> qd(q.begin(), q.begin()+Y);

    vector<ll> pqd;
    rep(i, pd.size()){
        pqd.push_back(pd[i]);
    }
    rep(i, qd.size()){
        pqd.push_back(qd[i]);
    }

    sort(pqd.begin(), pqd.end(), greater<ll>());
    vector<ll> sum;
    sum.push_back(0);

    ll tmp = 0;
    rep(i, pqd.size()){
        tmp += pqd[i];
        sum.push_back(tmp);
    }    
    //cout << pqd.size() << sum.size() <<endl;

    ll total_max = sum[pqd.size()];
    ll r_sum = 0;

    rep(i, r.size()){
        r_sum += r[i];
        if (i >= X + Y) break;
        ll total = r_sum + sum[X + Y - 1 - i];
        total_max = max(total_max, total);
    }

    cout << total_max << endl;
}

