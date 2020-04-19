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


#define BOLL_MAX 200050
ll boll_num[BOLL_MAX] = {0};

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    rep(i, n){ 
        int tmp; 
        cin >> tmp; 
        a.push_back(tmp);
        boll_num[tmp]++;
    }

    //rep(i,n) cout << boll_num[i] << endl;

    ll max_score = 0;
    rep1(i,n){
        ll score = (boll_num[i]) * (boll_num[i]-1) / 2;
        max_score += score;
    }
    rep(i, n){
        int num = a[i];
        ll minus = (boll_num[num] - 1);
        if (boll_num[num] <= 1) minus = 0;
        cout << max_score - minus << endl;
    }

}

