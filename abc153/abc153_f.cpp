#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<ll, ll> P;


auto compare = [](P a, P b){
    if (a.first != b.first){
        return a.first > b.first;
    } else {
        return a.second > b.second;
    }
};
priority_queue<P, vector<P>, decltype(compare)> pq(compare); 

int main()
{
    ll n, d, a;
    cin >> n >> d >> a;
    vector<P> xh;
    rep(i, n){ 
        ll tmpx, tmph; 
        cin >> tmpx >> tmph; 
        pq.push(P(tmpx, tmph));
    }

    ll ans = 0;
    ll power = 0;
    while(!pq.empty()){
        //printf("%lld %lld %lld\n", pq.top().first, pq.top().second, power);
        P point = pq.top();
        if (point.second > 0){
            //敵出現
            ll diff = point.second - power;
            if (diff > 0){
                //爆弾の威力が足りない
                ll bom = (diff-1)/a + 1;
                ans += bom;
                power += bom * a;
                pq.push(P((point.first + 2*d + 1), -(bom*a)));
            } 
        } else {
            power += point.second; 
        }
        pq.pop();
    }


    cout << ans << endl;
}

