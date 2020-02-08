#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a;
    rep(i, n){ int tmp; cin >> tmp; a.push_back(tmp);}

    ll ans = n * (n+1) / 2;
    ll ans_ = 0;
    int right = 0;
    
    ll sum = 0;
    rep(left, n){

        while(right < n && (sum + a[right]) < k){
            sum += a[right];
            ++right;
        }
        ans_ += (right - left);
        if (right == left) ++right;
        else sum -= a[left];
    }

    cout << ans - ans_ << endl;
}

