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

const int N_MAX = 200050;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<multiset<int>> rand(N_MAX);
    multiset<int> score;
    
    vector<P> enji(n+1);
    
    rep(i, n){
        int a, b;
        cin >> a >> b;
        enji[i+1].first = a;
        enji[i+1].second = b;
        rand[b].insert(a); 
    }

    rep(i, N_MAX){
        if (rand[i].size() == 0) continue;
        auto itr = rand[i].end();
        itr--;
        //cout << *itr << endl;        
        score.insert(*itr);
    }

    rep(i, q){
        int c, d;
        cin >> c >> d;

        //異動する園児の情報
        int rate = enji[c].first;
        int en = enji[c].second;

        int from_before = *(--(rand[en].end()));

        int to_before = -1;
        if (rand[d].size() != 0) to_before = *(--(rand[d].end()));
        rand[en].erase(rand[en].find(rate));
        rand[d].insert(rate);
        int from_after = -1;
        if (rand[en].size() != 0) from_after = *(--(rand[en].end()));
        int to_after = *(--(rand[d].end()));

        enji[c].second = d;

        score.erase(score.find(from_before));
        if(from_after != -1) score.insert(from_after);
        if(to_before != -1) score.erase(score.find(to_before));
        score.insert(to_after);


        auto itr = score.begin();
        cout << *itr << endl;
    }


}

